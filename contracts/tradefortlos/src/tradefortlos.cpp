#include "../include/tradefortlos.hpp"

tradefortlos::tradefortlos(name self, name code, datastream<const char *> ds) : contract(self, code, ds) {}

tradefortlos::~tradefortlos() {}

ACTION tradefortlos::noop() {

}

void tradefortlos::ontransfer(name from, name to, asset quantity, string memo)
{
    name rec = get_first_receiver();

    if (rec == CORE_SYM_ACCOUNT && from != get_self() && quantity.symbol == CORE_SYM)
    {
        action(permission_level{ get_self(), name("active") }, CORE_SYM_ACCOUNT, name("transfer"),
            make_tuple(get_self(),
                TLOS_BUYER,
                quantity,
                std::string("TLOS auto-buy")))
            .send();
        action(permission_level{ TLOS_BUYER, name("active") }, CORE_SYM_ACCOUNT, name("transfer"),
            make_tuple(TLOS_BUYER,
                name("newdexpocket"),
                quantity,
                std::string("{\"type\" : \"buy-market\", \"symbol\" : \"eosio.token-tlos-eos\", \"price\" : \"0.000000\", \"channel\" : \"web\", \"receiver\" : \"" + memo + "\"}")))
            .send();
    }
}