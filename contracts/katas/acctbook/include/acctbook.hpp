#pragma once
#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

/**
 * kata_accounting
 *
 * @details https://github.com/EOSIO/devdocs/wiki/Katas-Accounting
 *
 * [TBD] Implement maximum balance functionality from the last paragraph.
 */
class [[eosio::contract("acctbook")]] acctbook : public eosio::contract {
public:
    acctbook(const eosio::name& receiver, const eosio::name& code,  eosio::datastream<const char*> ds): contract(receiver, code, ds) {}

    /**
     * Add account
     *
     * @details create account, and category default. If account already exists, no action except err msg
     *
     * @return   false when account exists, otherwise true
     *
     * @param user - account name
     */
    [[eosio::action]]
    bool addacct(const eosio::name& user);

    /**
     * Add category
     *
     * @details  create category for the given account. If account/category exists, no action except err msg
     *
     * @return   false when account or category exists, otherwise true
     *
     * @param user - account name
     * @param cat_name - category name
     */
    [[eosio::action]]
    bool addcat(const eosio::name& user, const std::string& cat_name);

    /**
     * Print account
     *
     * @details  Print account and all associated categories, if account does not exist, print err msg
     *
     * @return   false when account does not exist, otherwise true
     *
     * @param user - account name
     */
    [[eosio::action]]
    bool printacct(const eosio::name& user);

    /**
     * Assignfund
     *
     * @details  Set amount to default category for account
     *
     * @return   false when account does not exist or negative fund, otherwise true
     *
     * @param user - account name
     * @param amount - fund being set in default category
     */
    [[eosio::action]]
    bool assignfund(const eosio::name& user, const eosio::asset& amount);

    /**
     * transfund
     *
     * @details  transfer fund from one category to another category within an account or between accounts,
     *           No action when amount is 0.0 or between same account and same category
     *
     * @return   as transfer returns
     *
     * @param user - Initiate account (sender when amount is positive, receiver when amount is negative)
     * @param cat_from - Category of initiating account
     * @param acct_to - related account (sender when amount is negative, receiver when amount is positive)
     * @param cat_to - Category of related account
     * @param amount - amount being transferred
     */
    [[eosio::action]]
    bool transfund(const eosio::name& user, const std::string& cat_from, const eosio::name& acct_to, const std::string& cat_to, const eosio::asset& amount);

    /**
     * GetBalance
     *
     * @details  Get balance for given account and category
     *
     * @return   option of balance for the given account and category
     *
     * @param user - account name
     * @param cat_name - category name
     *
     *  @pre: amount is positive
     */
    [[eosio::action]]
    std::optional<eosio::asset> getbalance(const eosio::name& user, const std::string& cat_name);
protected:

    /**
     * printErrNegativeTransfer
     *
     * @details  print err msg when transfer nagative fund
     *
     * @param amount - amount being transfered
     */
    void printErrTransferNegFund(const eosio::asset& amount) const;

    /**
     * printErrAssignNegFund
     *
     * @details  print err msg when assigning negative fund
     *
     * @param acct - account name
     * @param amount - amount being assigned
     */
    void printErrAssignNegFund(const eosio::name& acct, const eosio::asset& amount) const;

    /**
     * printErrNotHumanReadable
     *
     * @details  print err msg for not human readable msg
     *
     * @param cat_name - category name
     */
    void printErrNotHumanReadable(const std::string& cat_name) const;

    /**
     * printErrNotEnoughFund
     *
     * @details  print err msg for fund is not enough (for transfer)
     *
     * @param acct - account name
     * @param cat - category name
     * @param balance - current balance on category
     * @param amount - amount (to be transferred)
     */
    void printErrNotEnoughFund(const eosio::name& acct, const std::string& cat, const eosio::asset& balance, const eosio::asset& amount) const;

    /**
     * printErrNotExistAcct
     *
     * @details  print err msg for account can not be found
     *
     * @param acct - account name
     */
    void printErrNotExistAcct(const eosio::name& acct) const;

    /**
     * printErrNotExistCategoty
     *
     * @details  print err msg for category can not be found
     *
     * @param cat - category name
     */
    void printErrNotExistCategoty(const std::string& cat_name) const;

    /**
     * printErrAlreadyExistAcct
     *
     * @details  print err msg for account already exists
     *
     * @param acct - account name
     */
    void printErrAlreadyExistAcct(const eosio::name& acct) const;

    /**
     * printErrAlreadyExistCategoty
     *
     * @details  print err msg for category already exists
     *
     * @param cat - category name
     */
    void printErrAlreadyExistCategoty(const std::string& cat_name) const;

    /**
     * printErrSymbolNotMatch
     *
     * @details  print err msg for symbol mismatch
     *
     * @param s1 - symbol 1
     * @param s2 - symbol 2
     */
    void printErrSymbolNotMatch(const eosio::symbol& s1, const eosio::symbol& s2) const;
    /*
     * struct category
     */
private:
    static const char* DEFAULT_CATEGORY;
    static constexpr int MEMO_SIZE = 256;
    struct category {
        static bool isHumanReadable(const std::string &str) {
            for (size_t idx = 0; idx < str.size(); ++idx) {
                if ( ((str.at(idx) < '0') || (str.at(idx) > '9')) &&
                     ((str.at(idx) < 'a') || (str.at(idx) > 'z')) &&
                     ((str.at(idx) < 'A') || (str.at(idx) > 'Z'))){
                    return false;
                }
            }
            return true;
        }
        std::string cat_name;
        uint64_t cat_id;
        eosio::asset cat_balance;
        category() = default;
        category(const std::string& name)
        : cat_name(name)
        , cat_id(std::hash<std::string>{}(cat_name))
        , cat_balance(0, eosio::symbol("SYS", 4))
        {
        }
        void setBalance(const eosio::asset& balance) { cat_balance = balance; }
        void changeBalance(const eosio::asset& delta) { cat_balance = delta; }
        EOSLIB_SERIALIZE( category, (cat_name)(cat_id)(cat_balance) )
    };

    /*
     * struct acct
     */
    struct [[eosio::table]] acct {
        eosio::name acct_name;
        std::vector<category> cat_list;
        uint64_t primary_key() const { return acct_name.value; }
        EOSLIB_SERIALIZE( acct, (acct_name)(cat_list) )
    };
    typedef eosio::multi_index<"account"_n, acct> acct_index;
};
