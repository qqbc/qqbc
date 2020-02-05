#include <boost/test/unit_test.hpp>
#include "eosio.system_tester.hpp"
//#include "../include/acctbook.hpp"

using namespace eosio::chain;
using namespace eosio::testing;
using namespace eosio_system;
using namespace fc;

struct acctbook_tester: public tester {
    acctbook_tester() {
        produce_blocks( 2 );

        // NOTE: account names have to be 12 chars on real chain
        //

        create_accounts( { N(accnt1), N(accnt2), N(accnt3), N(acctbook), N(eosio.token) } );
        produce_blocks( 2 );

        set_code( N(eosio.token), contracts::token_wasm() );
        set_abi( N(eosio.token), contracts::token_abi().data() );

        set_code( N(acctbook), contracts::acctbook_wasm() );
        set_abi( N(acctbook), contracts::acctbook_abi().data() );

        produce_blocks();

        {
            const auto& accnt = control->db().get<account_object,by_name>( N(acctbook) );
            abi_def abi;

            BOOST_REQUIRE_EQUAL(abi_serializer::to_abi(accnt.abi, abi), true);

            abi_ser.set_abi(abi, abi_serializer_max_time);
        }

        {
            const auto& accnt = control->db().get<account_object,by_name>( N(eosio.token) );
            abi_def abi;

            BOOST_REQUIRE_EQUAL(abi_serializer::to_abi(accnt.abi, abi), true);

            tok_abi_ser.set_abi(abi, abi_serializer_max_time);
        }

        base_tester::push_action( N(eosio.token), N(create), N(eosio.token), mvo()
                ("issuer", "eosio.token")
                ("maximum_supply", SYS_10000_0000));

        base_tester::push_action( N(eosio.token), N(issue), N(eosio.token), mvo()
                ("to", "eosio.token")
                ("quantity", SYS_10000_0000)
                ("memo", "issue all tokens to token accnt"));

        base_tester::push_action( N(eosio.token), N(transfer), N(eosio.token), mvo()
                ("from", "eosio.token")
                ("to", "accnt1")
                ("quantity", SYS_2000_0000)
                ("memo", "issue 2000 to accnt1"));

        base_tester::push_action( N(eosio.token), N(transfer), N(eosio.token), mvo()
                ("from", "eosio.token")
                ("to", "accnt2")
                ("quantity", SYS_2000_0000)
                ("memo", "issue 2000 to accnt2"));

        base_tester::push_action( N(eosio.token), N(transfer), N(eosio.token), mvo()
                ("from", "eosio.token")
                ("to", "accnt3")
                ("quantity", SYS_2000_0000)
                ("memo", "issue 2000 to accnt2"));

        // assign "eosio.token" to acctbook account for assign
        base_tester::push_action( N(eosio.token), N(transfer), N(eosio.token), mvo()
                ("from", "eosio.token")
                ("to", "acctbook")
                ("quantity", SYS_2000_0000)
                ("memo", "issue 2000 to acctbook"));

        produce_blocks();
    }

    void add_acct( const name& acct_name ) {
        base_tester::push_action( N(acctbook), N(addacct), acct_name, mvo()
                ("user", acct_name));
    }

    void add_cat( const name& acct_name, const std::string& cat_name ) {
        base_tester::push_action( N(acctbook), N(addcat), acct_name, mvo()
                ("user", acct_name)
                ("cat_name", cat_name));
    }

    void assign_fund( const name& acct_name, const asset& fund) {
        base_tester::push_action( N(acctbook), N(assignfund), acct_name, mvo()
                ("user", acct_name)
                ("amount", fund));
    }

    void get_fund( const name& acct_name, const std::string& cat_name) {
        base_tester::push_action( N(acctbook), N(getbalance), acct_name, mvo()
                ("user", acct_name)
                ("cat_name", cat_name));
    }


    void transfer_fund( const name& acct_from, const std::string& cat_from, const name& acct_to, const std::string& cat_to, const asset& amount) {

        base_tester::push_action( N(acctbook), N(transfund), acct_from, mvo()
                ("user", acct_from)
                ("cat_from", cat_from)
                ("acct_to", acct_to)
                ("cat_to", cat_to)
                ("amount", amount));
    }

    // Get balance for given account and category
    asset get_fund_balance( const name& acct_name, const std::string& cat_name) {
        const auto& var =
                abi_ser.binary_to_variant("acct",
                                          get_row_by_account(N(acctbook), N(acctbook), N(account), acct_name), // code , scope, table, primary key value
                                          abi_serializer_max_time);
//        wdump((var));
        const auto& cat_list = var["cat_list"];

        for(size_t idx=0; idx<cat_list.size(); ++idx)
        {
            if (cat_name == cat_list[idx]["cat_name"])
            {
                return asset::from_string(cat_list[idx]["cat_balance"].as_string());
            }
        }
        return INVALID_0_0001;
    }

    abi_serializer tok_abi_ser;
    abi_serializer abi_ser;
    const asset SYS_10000_0000 = asset::from_string("10000.0000 SYS");
    const asset SYS_2000_0000 = asset::from_string("2000.0000 SYS");
    const asset SYS_0_0000 = asset::from_string("0.0000 SYS");
    const asset SYS_123_1234 = asset::from_string("123.1234 SYS");
    const asset SYS_234_3456 = asset::from_string("234.3456 SYS");
    const asset SYS_3456_1234 = asset::from_string("3456.1234 SYS");
    const asset SYS_1_2345 = asset::from_string("1.2345 SYS");
    const asset SYS_2_3456 = asset::from_string("1.2345 SYS");
    const asset SYS_40_3456 = asset::from_string("40.3456 SYS");
    const asset INVALID_0_0001 = asset::from_string("0.0001 INVALID");
    const asset SYS_NEG_23_5678 = asset::from_string("-23.5678 SYS");
    const asset SYS_NEG_5678_1234 = asset::from_string("-5678.1234 SYS");

    const std::string CAT_DEFAULT = "default";
    const std::string CAT_RENT = "rent";
    const std::string CAT_VACATION = "vacation";
};


BOOST_FIXTURE_TEST_CASE( create_acct_test, acctbook_tester )try {
    BOOST_REQUIRE_NO_THROW( add_acct(N(accnt1)) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_0_0000);
} FC_LOG_AND_RETHROW()


BOOST_FIXTURE_TEST_CASE( create_acct_fail_test, acctbook_tester )try {
    // create an invalid account
    BOOST_REQUIRE_THROW( add_acct(N(accntinvalid)), transaction_exception );
} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( create_cat_test, acctbook_tester )try {
    // create an account
    BOOST_REQUIRE_NO_THROW( add_acct(N(accnt1)) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_0_0000);
    // create the category
    BOOST_REQUIRE_NO_THROW( add_cat(N(accnt1), CAT_RENT) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_RENT), SYS_0_0000);
} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( create_cat_fail_test, acctbook_tester )try {
    // create an account
    BOOST_REQUIRE_NO_THROW( add_acct(N(accnt1)) );
    // create the category
    BOOST_REQUIRE_NO_THROW( add_cat(N(accnt1), CAT_RENT) );
    // create duplicated category
    BOOST_REQUIRE_THROW( add_cat(N(accnt1), CAT_RENT), transaction_exception  );
    // create valid category to non-exist account
    BOOST_REQUIRE_THROW( add_cat(N(accntinvalid), CAT_VACATION), transaction_exception  );
} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( assign_fund_test, acctbook_tester )try {
    // create an account
    BOOST_REQUIRE_NO_THROW( add_acct(N(accnt1)) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_0_0000);
    // create the category
    BOOST_REQUIRE_NO_THROW( assign_fund(N(accnt1), SYS_123_1234) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_123_1234);
    // assign fund 
    BOOST_REQUIRE_NO_THROW( assign_fund(N(accnt1), SYS_234_3456) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);
} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( assign_fund_fail_test, acctbook_tester )try {
    // create an account
    BOOST_REQUIRE_NO_THROW( add_acct(N(accnt1)) );
    // assign fund to invalid accout
    BOOST_REQUIRE_THROW( assign_fund(N(accnt1invalid), SYS_123_1234), transaction_exception );
    // assign fund to invalid accout
    BOOST_REQUIRE_NO_THROW( assign_fund(N(accnt1), SYS_NEG_23_5678) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_0_0000);
} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( transfer_fund_test, acctbook_tester )try {
    // create an account
    BOOST_REQUIRE_NO_THROW( add_acct(N(accnt1)) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_0_0000);
    // assign fund 
    BOOST_REQUIRE_NO_THROW( assign_fund(N(accnt1), SYS_234_3456) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);
    // create the category
    BOOST_REQUIRE_NO_THROW( add_cat(N(accnt1), CAT_RENT) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_RENT), SYS_0_0000);

    // transfer fund from "default "to "rent, same account different categories
    BOOST_REQUIRE_NO_THROW( transfer_fund( N(accnt1), CAT_DEFAULT, N(accnt1), CAT_RENT, SYS_123_1234) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), (SYS_234_3456 - SYS_123_1234) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_RENT), SYS_123_1234 );

    // same account and category transfer, nothing change
    BOOST_REQUIRE_NO_THROW( transfer_fund( N(accnt1), CAT_RENT, N(accnt1), CAT_RENT, SYS_1_2345) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_RENT), SYS_123_1234 );

    // same account and category over draw, no change
    BOOST_REQUIRE_NO_THROW( transfer_fund( N(accnt1), CAT_DEFAULT, N(accnt1), CAT_RENT, SYS_3456_1234) );
} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( transfer_fund_fail_test, acctbook_tester )try {
    // create an account
    BOOST_REQUIRE_NO_THROW ( add_acct(N(accnt1)));
    // assign fund
    BOOST_REQUIRE_NO_THROW( assign_fund(N(accnt1), SYS_234_3456) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);

    // transfer from not existing account, no change
    BOOST_REQUIRE_NO_THROW( transfer_fund( N(accnt2), CAT_DEFAULT, N(accnt1), CAT_DEFAULT, SYS_40_3456) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);

    // transfer to not existing account, no change
    BOOST_REQUIRE_NO_THROW( transfer_fund( N(accnt1), CAT_DEFAULT, N(accnt2), CAT_DEFAULT, SYS_40_3456) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);

    // add category
    BOOST_REQUIRE_NO_THROW( add_cat(N(accnt1), CAT_RENT) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_RENT), SYS_0_0000);

    // transfer negative fund, no change
    BOOST_REQUIRE_NO_THROW( transfer_fund( N(accnt1), CAT_DEFAULT, N(accnt1), CAT_RENT, SYS_NEG_23_5678) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_RENT), SYS_0_0000);

    // create an account
    BOOST_REQUIRE_NO_THROW ( add_acct(N(accnt2)));

    // transfer from not existing category, no change
    BOOST_REQUIRE_NO_THROW( transfer_fund( N(accnt2), CAT_RENT, N(accnt1), CAT_DEFAULT, SYS_40_3456) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);

    // transfer to not existing account, no change
    BOOST_REQUIRE_NO_THROW( transfer_fund( N(accnt1), CAT_DEFAULT, N(accnt2), CAT_RENT, SYS_40_3456) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);

    // transfer different currency, no change
    BOOST_REQUIRE_NO_THROW( transfer_fund( N(accnt1), CAT_DEFAULT, N(accnt2), CAT_VACATION, INVALID_0_0001) );
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt1), CAT_DEFAULT), SYS_234_3456);
    // check fund
    BOOST_CHECK_EQUAL( get_fund_balance(N(accnt2), CAT_DEFAULT), SYS_0_0000);

} FC_LOG_AND_RETHROW()