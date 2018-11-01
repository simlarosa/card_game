/*---------------------------------
File property: Simone La Rosa
Project: EOS Smart Contracts card-game
Description: Following an EOS Tutorial build a Dapp
             on Eos for learning EOS development
Date: 1 November 2018
-------------------------------- */

// cardgame.hpp is where we define the interface of the smart contracts

#include <eosiolib/eosio.hpp>

using namespace std;
//We create a constructor which calls the constructor of the base class
class cardgame : public eosio::contract {

  private:
//For the game we need to store the players information we will use a multi index table

// @abi table users
struct user_info {
   account_name    name;
   uint16_t        win_count = 0;
   uint16_t        lost_count = 0;

//We need to define a primary_key for our table that will use the first field of the table
   auto primary_key() const { return name; }
 };

//we create a type that refers to a multi index table, that is a users table aliasing as users_table
 typedef eosio::multi_index<N(users), user_info> users_table;

//we create a variable fo the multi index table
 users_table _users;

  public:

//We pass the name of the account that owns the contract and also a variable initialization of multiindex table to the constructor (self).
cardgame( account_name self ):contract(self),_users(self, self){}

//We create a login action
void login(account_name username);


};
