#pragma once
#include <string>
#include "cart.h"
#include "store.h"

struct menu { //all user input and menu functionality here & in menu.cpp
	std::string welcome_msg = "Welcome to the store!";
	int user_choice = 0;
	cart cart;
	store store;
	enum user_options {
		ADD_ITEM,
		REMOVE_ITEM,
		VIEW_CART,
		VIEW_STORE_ITEMS,
		CHECK_OUT,
		EXIT,
		INVALID_INPUT = -1
	};
	






	void welcome() const;
	int get_user_choice(std::string prompt) const; //use getline to get the users input, will return their choice (an int)
	bool get_confirmation() const; //prompt user to enter Y or N to confirm their action

	//Menu options; call the associated item, cart, or store function here.
	void start(); //start the menu/program loop
	void quit() const; //MVP 3
	void print_store_items() const;
	//add the rest
};