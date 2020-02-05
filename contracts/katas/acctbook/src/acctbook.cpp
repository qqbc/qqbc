#include <acctbook.hpp>
#include <eosio/system.hpp>
#include <eosio.token/eosio.token.hpp>

using namespace eosio;

const char* acctbook::DEFAULT_CATEGORY = "default";

[[eosio::action]]
bool acctbook::addacct(const name& user) {
    require_auth(user);
    acct_index accts(get_self(), get_first_receiver().value);

    auto itr = accts.find(user.value);
    if( itr == accts.end() )
    {
        accts.emplace(user, [&]( auto& row ) {
            row.acct_name = user;
            row.cat_list.emplace_back(DEFAULT_CATEGORY);
            print("Info: added account:", user, " and category:", DEFAULT_CATEGORY);
        });
        return true;
    }

    printErrAlreadyExistAcct(user);
    return false;
}

[[eosio::action]]
bool acctbook::addcat(const name& user, const std::string& cat_name) {
    require_auth(user);
    acct_index accts(get_self(), get_first_receiver().value);

    if (!category::isHumanReadable(cat_name))
    {
        printErrNotHumanReadable(cat_name);
        return false;
    }
    auto itr = accts.find(user.value);
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
        print("Info: category:", cat_name, " for user:", user);
        return true;
    }
    printErrNotExistAcct(user);
    return false;
}

[[eosio::action]]
bool acctbook::printacct(const name& user) {
    require_auth(user);
    acct_index accts(get_self(), get_first_receiver().value);

    auto itr = accts.find(user.value);
    if( itr != accts.end() )
    {
        print("account:[", user, "]");
        for(const auto& c : itr->cat_list)
        {
            print(", category:[", c.cat_name, "], id:[", c.cat_id, "], balance:[", c.cat_balance, "]");
        }
        return true;
    }

    printErrNotExistAcct(user);
    return false;
}

[[eosio::action]]
bool acctbook::assignfund(const name& user, const eosio::asset& amount) {
    require_auth(user);
    acct_index accts(get_self(), get_first_receiver().value);

    if (amount.amount < 0)
    {
        printErrAssignNegFund(user, amount);
        return false;
    }
    auto itr = accts.find(user.value);
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

            std::string memo = "Transfer token:" + amount.to_string() + " from eosio.token to " + user.to_string();
            if (memo.size() > MEMO_SIZE)
            {
                memo.resize(MEMO_SIZE);
            }

            eosio::token::transfer_action transfer_act("eosio.token"_n, { get_self(), "active"_n });
            transfer_act.send(get_self(), user, amount, memo);

            print("Info: assigned default category, amount:", amount);
        }
        return true;
    }

    printErrNotExistAcct(user);
    return false;
}

[[eosio::action]]
std::optional<eosio::asset> acctbook::getbalance(const eosio::name& user, const std::string& cat_name)
{
    require_auth(user);
    acct_index accts(get_self(), get_first_receiver().value);

    auto itr = accts.find(user.value);
    if( itr != accts.end() )
    {
        size_t idx = 0;
        for(; idx < itr->cat_list.size(); ++idx)
        {
            if (itr->cat_list[idx].cat_name == cat_name)
            {
                break;
            }
        }
        if ((itr->cat_list.empty()) || (idx == itr->cat_list.size()))
        {
            printErrNotExistCategoty(cat_name);
            return {};
        }
        print("Info: getbalance, account:", user, ", category:", cat_name, ", balance:", itr->cat_list[idx].cat_balance);
        return itr->cat_list[idx].cat_balance;
    }

    printErrNotExistAcct(user);
    return {};
}

[[eosio::action]]
bool acctbook::transfund(const name& acct_from, const std::string& cat_from, const name& acct_to, const std::string& cat_to, const eosio::asset& amount) {
    require_auth(acct_from);

    if (amount.amount < 0.0)
    {
        printErrTransferNegFund(amount);
        return false;
    } else if (amount.amount == 0.0)
    {
        print("Warning: No action to transfer amount:", amount);
        return true;
    }

    if ((acct_from == acct_to) && (cat_from == cat_to))
    {
        print("Warning: No action to transfer fund to the same account:", acct_from, " and category:", cat_from);
        return true;
    }

    if (acct_from != acct_to)
    {
        print("Warning: phase 1 allows transfering within account only, from:", acct_from, " and to:", acct_to);
        return false;
    }

    acct_index accts(get_self(), get_first_receiver().value);
    auto itr_from = accts.find(acct_from.value);
    if (itr_from == accts.end()) {
        printErrNotExistAcct(acct_from);
        return false;
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
        printErrNotExistCategoty(cat_from);
        return false;
    }

    if (itr_from->cat_list[idx_from].cat_balance.symbol != amount.symbol)
    {
        printErrSymbolNotMatch(itr_from->cat_list[idx_from].cat_balance.symbol, amount.symbol);
        return false;
    }

    auto itr_to = accts.find(acct_to.value);
    if (itr_to == accts.end()) {
        printErrNotExistAcct(acct_to);
        return false;
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
        printErrNotExistCategoty(cat_to);
        return false;
    }

    if (itr_to->cat_list[idx_to].cat_balance.symbol != amount.symbol)
    {
        printErrSymbolNotMatch(itr_to->cat_list[idx_to].cat_balance.symbol, amount.symbol);
        return false;
    }

    if (itr_from->cat_list[idx_from].cat_balance < amount)
    {
        printErrNotEnoughFund(acct_from, cat_from, itr_from->cat_list[idx_from].cat_balance, amount);
        return false;
    }


    accts.modify(itr_from, acct_from, [&](auto &row) {
        row.cat_list[idx_from].cat_balance -= amount;
    });
    accts.modify(itr_to, acct_to, [&](auto &row) {
        row.cat_list[idx_to].cat_balance += amount;
    });

    print("Info: transfered amount:", amount.to_string(), " from account:", acct_from, ", category:", cat_from, " --> account:", acct_to, ", category:", cat_to);
    return true;
}

void acctbook::printErrTransferNegFund(const eosio::asset& amount) const
{
    print("Error: Can not transfer negative fund:", amount);
}

void acctbook::printErrSymbolNotMatch(const eosio::symbol& s1, const eosio::symbol& s2) const
{
    print("Error: Can not covert between symbol:[", s1, "] and:[", s2, "]");
}

void acctbook::printErrAssignNegFund(const name& acct, const eosio::asset& amount) const
{
    print("Error: Assigned negative fund:", acct, ", amount:", amount);
}

void acctbook::printErrNotHumanReadable(const std::string& cat_name) const
{
    print("Error: Not valid category name:", cat_name, " Please enter [0-9|a-z|A-Z]");
}

void acctbook::printErrNotEnoughFund(const name& acct, const std::string& cat, const eosio::asset& balance, const eosio::asset& amount) const
{
    print("Error: Not enough fund, account:", acct, ", category:", cat, ", balance:", balance.to_string(), ", amoumt:", amount.to_string());
}

void acctbook::printErrNotExistAcct(const name& acct) const
{
    print("Error: Not exist account:", acct);
}

void acctbook::printErrNotExistCategoty(const std::string& cat_name) const
{
    print("Error: Not exist category:", cat_name);
}

void acctbook::printErrAlreadyExistAcct(const name& acct) const
{
    print("Error: Already exists account:", acct);
}

void acctbook::printErrAlreadyExistCategoty(const std::string& cat_name) const
{
    print("Error: Already exists category:", cat_name);
}
