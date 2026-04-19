#pragma once
#include <string>
#include "cart.h"
#include "store.h"

struct menu {
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
	int get_user_choice(std::string prompt) const;
	bool get_confirmation() const; //prompts user to enter Y or N to confirm their action

	//Menu options
	void start(); //start the program loop
	void quit() const;
	void print_store_items() const;
	void print_cart_items() const;
	void add_item();
	void checkout() const;
};