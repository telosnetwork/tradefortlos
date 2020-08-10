#include <eosio/eosio.hpp>
#include <eosio/symbol.hpp>
#include <eosio/asset.hpp>

using namespace std;
using namespace eosio;

CONTRACT tradefortlos : public contract
{

public:
    tradefortlos(name self, name code, datastream<const char *> ds);

    ~tradefortlos();

    static constexpr name CORE_SYM_ACCOUNT = name("eosio.token");
    static constexpr symbol CORE_SYM = symbol("EOS", 4);

    ACTION noop();

    [[eosio::on_notify("eosio.token::transfer")]] void ontransfer(name from, name to, asset quantity, string memo);

};