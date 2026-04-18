#pragma once
#include <string>
#include "cart.h"
#include "store.h"

using std::string;

struct menu { //all user input and menu functionality here & in menu.cpp
	string welcome_msg = "Welcome to the store!";
	int user_choice = 0;
	cart cart;
	store store;
	enum options {
		ADD_ITEM = 1,
		VIEW_CART = 2,
		VIEW_STORE_ITEMS = 3,
		CHECK_OUT = 4,
		EXIT = 5
	};
	






	void welcome() const;
	int get_user_choice() const; //use getline to get the users input, will return their choice (an int)

	//Menu options; call the associated item, cart, or store function here.
	void start(); //start the menu loop
	void quit() const; //MVP 3
	void print_store_items() const;
	//add the rest
};