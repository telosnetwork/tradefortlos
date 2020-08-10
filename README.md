# EOSIO Contract Template
A template repository for EOSIO contracts.

## Dependencies

* eosio.cdt
* nodeos, cleos, keosd

## Setup

To begin, navigate to the project directory: `eosio-contract-template/`

    mkdir build && mkdir build/messager

    chmod +x build.sh

    chmod +x deploy.sh

The `tradefortlos` contract has already been implemented and is build-ready.

## Build

    ./build.sh contract-name

## Deploy

    ./deploy.sh contract-name account-name { mainnet | testnet | local }
