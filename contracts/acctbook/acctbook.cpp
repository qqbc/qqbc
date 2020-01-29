#include <eosio/eosio.hpp>
//#include "abcounter.cpp"

using namespace eosio;

class [[eosio::contract("acctbook")]] acctbook : public eosio::contract {

public:
    acctbook(const name& receiver, const name& code,  datastream<const char*> ds): contract(receiver, code, ds) {}

    [[eosio::action]]
    void addacct(const name& user, const name& acct_name) {
        require_auth(user);
        acct_index accts(get_self(), get_first_receiver().value);

        auto itr = accts.find(acct_name.value);
        if( itr == accts.end() )
        {
            accts.emplace(user, [&]( auto& row ) {
                row.acct_name = acct_name;
                row.cat_list.emplace_back(DEFAULT_CATEGORY);
                print("Info: added account:", acct_name, "and category:", DEFAULT_CATEGORY);
            });
        } else{
            printErrAlreadyExistAcct(acct_name);
        }
    }
    [[eosio::action]]
    void addcat(const name& user, const name& acct_name, const std::string& cat_name) {
        require_auth(user);
        acct_index accts(get_self(), get_first_receiver().value);

        if (!category::isHumanReadable(cat_name))
        {
            printErrNotHumanReadable(cat_name);
            return;
        }
        auto itr = accts.find(acct_name.value);
        if( itr != accts.end() )
        {
            size_t idx=0;
            for(; idx<itr->cat_list.size(); ++idx)
            {
                if (itr->cat_list[idx].cat_name == cat_name)
                {
                    printErrAlreadyExistCategoty(cat_name);
                    break;
                }
            }
            if (idx == itr->cat_list.size()) {
                accts.modify(itr, user, [&](auto &row) {
                    row.cat_list.emplace_back(cat_name);
                });
            }
        } else
        {
            printErrNotExistAcct(acct_name);
        }
    }
    [[eosio::action]]
    void printacct(const name& user, const name& acct_name) {
        require_auth(user);
        acct_index accts(get_self(), get_first_receiver().value);

        auto itr = accts.find(acct_name.value);
        if( itr != accts.end() )
        {
            print("account:[", acct_name, "]");
            for(const auto& c : itr->cat_list)
            {
                print(", category:[", c.cat_name, "], id:[", c.cat_id, "], balance:[", doubleToStr(c.cat_balance), "]");
            }
        } else{
            printErrNotExistAcct(acct_name);
        }
    }
    [[eosio::action]]
    void assignfund(const name& user, const name& acct_name, const double amount) {
        require_auth(user);
        acct_index accts(get_self(), get_first_receiver().value);

        if (amount < 0.0)
        {
            printErrAssignNegFund(acct_name, amount);
            return ;
        }
        auto itr = accts.find(acct_name.value);
        if( itr != accts.end() )
        {
            if (itr->cat_list.empty() || (itr->cat_list[0].cat_name != DEFAULT_CATEGORY))
            {
                printErrNotExistCategoty(DEFAULT_CATEGORY);
            } else
            {
                accts.modify(itr, user, [&](auto &row) {
                    row.cat_list[0].cat_balance = amount;
                });
                print("Info: assigned default category, amount:", doubleToStr(amount));
            }
        } else{
            printErrNotExistAcct(acct_name);
        }
    }

    [[eosio::action]]
    void transfund(const name& user, const name& acct_from, const std::string& cat_from, const name& acct_to, const std::string& cat_to, const double amount) {
        require_auth(user);

        if ((acct_from != acct_to) || (cat_from != cat_to)) {
            if (amount > 0.0)
            {
                transfer(user, acct_from, cat_from, acct_to, cat_to, amount);
            } else
            {
                transfer(user, acct_to, cat_to, acct_from, cat_from, -1.0 * amount);
            }
        } else
        {
            print("Warning: No action to transfer fund to the same account:", acct_from, " and category:", cat_from);
        }
    }
private:
    static const char* DEFAULT_CATEGORY;
    static constexpr int PRESION_SIZE = 4;
    static constexpr int PRESION_MUL = 10000;
    static constexpr double PRESION_DELTA = 0.5 / PRESION_MUL;
    std::string doubleToStr(const double num) const
    {
        const double num_upper = (num > 0.0) ? (num + PRESION_DELTA) : (num - PRESION_DELTA);
        const long long num_int = num_upper;
        const long long num_ll = (num_upper * PRESION_MUL);
        long long num_rem = abs(num_ll) % PRESION_MUL;

        std::string str_ret = std::to_string(num_int) + ".";
        const std::string str_rem = std::to_string(num_rem);
        const int fill_zero_num = PRESION_SIZE - str_rem.size();
        if (fill_zero_num > 0)
        {
            str_ret.append(fill_zero_num, '0');
        }
        return (str_ret + str_rem);
    }
    /*  @pre: amount should be positive
     */
    void transfer(const name& user, const name& acct_from, const std::string& cat_from, const name& acct_to, const std::string& cat_to, const double amount)
    {
        acct_index accts(get_self(), get_first_receiver().value);
        auto itr_from = accts.find(acct_from.value);
        auto itr_to = accts.find(acct_to.value);
        if (itr_from == accts.end()) {
            printErrNotExistAcct(acct_from);
            return;
        }
        if (itr_to == accts.end()) {
            printErrNotExistAcct(acct_to);
            return;
        }
        size_t idx_from = 0;
        for(; idx_from < itr_from->cat_list.size(); ++idx_from)
        {
            if (itr_from->cat_list[idx_from].cat_name == cat_from)
            {
                break;
            }
        }
        if (idx_from == itr_from->cat_list.size())
        {
            printErrAlreadyExistCategoty(cat_from);
            return;
        }
        size_t idx_to = 0;
        for(; idx_to < itr_to->cat_list.size(); ++idx_to)
        {
            if (itr_to->cat_list[idx_to].cat_name == cat_to)
            {
                break;
            }
        }
        if (idx_to == itr_to->cat_list.size())
        {
            printErrAlreadyExistCategoty(cat_to);
            return;
        }
        if (!hasEnoughFund(itr_from->cat_list[idx_from].cat_balance, amount))
        {
            printErrNotEnoughFund(acct_from, cat_from, itr_from->cat_list[idx_from].cat_balance, amount);
            return;
        }
        accts.modify(itr_from, user, [&](auto &row) {
            row.cat_list[idx_from].cat_balance -= amount;
        });
        accts.modify(itr_to, user, [&](auto &row) {
            row.cat_list[idx_to].cat_balance += amount;
        });
        print("Info: transfered amount:", doubleToStr(amount), " from account:", acct_from, ", category:", cat_from, " --> account:", acct_to, ", category:", cat_to);
    }
    void printErrAssignNegFund(const name& acct, const double amount) const
    {
        print("Error: Assigned negative fund:", acct, ", amount:", doubleToStr(amount));
    }
    void printErrNotHumanReadable(const std::string& cat_name) const
    {
        print("Error: Not valid category name:", cat_name, " Please enter [0-9|a-z|A-Z]");
    }
    void printErrNotEnoughFund(const name& acct, const std::string& cat, const double balance, const double amount) const
    {
        print("Error: Not enough fund, account:", acct, ", category:", cat, ", balance:", doubleToStr(balance), ", amoumt:", doubleToStr(amount));
    }
    void printErrNotExistAcct(const name& acct) const
    {
        print("Error: Not exist account:", acct);
    }
    void printErrNotExistCategoty(const std::string& cat_name) const
    {
        print("Error: Not exist category:", cat_name);
    }
    void printErrAlreadyExistAcct(const name& acct) const
    {
        print("Error: Already exists account:", acct);
    }
    void printErrAlreadyExistCategoty(const std::string& cat_name) const
    {
        print("Error: Already exists category:", cat_name);
    }
    // @pre: both balance and amount are positive
    bool hasEnoughFund(const double balance, const double amount) const
    {
        if ((balance + PRESION_DELTA) * PRESION_MUL < (amount + PRESION_DELTA) * PRESION_MUL)
        {
            return false;
        }
        return true;
    }
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
        double cat_balance;
        category() = default;
        category(const std::string& name)
        : cat_name(name)
        , cat_id(std::hash<std::string>{}(cat_name))
        , cat_balance(0.0)
        {
        }
        void setBalance(double balance) { cat_balance = balance; }
        void changeBalance(double delta) { cat_balance += delta; }
        EOSLIB_SERIALIZE( category, (cat_name)(cat_id)(cat_balance) )
    };
    struct [[eosio::table]] acct {
        name acct_name;
        std::vector<category> cat_list;
        uint64_t primary_key() const { return acct_name.value; }
        EOSLIB_SERIALIZE( acct, (acct_name)(cat_list) )
    };
    typedef eosio::multi_index<"account"_n, acct> acct_index;
};

const char* acctbook::DEFAULT_CATEGORY = "default";