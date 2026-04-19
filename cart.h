#pragma once
#include <vector>
#include "item.h"

using std::vector;

struct cart {
	vector<item> cart_inventory; //starts empty

	void add_item(item item); //check if store quanitity exists, remove n items from store, add n items to cart_inventory.
	void remove_item(item item);
	void sort(); //(Stretch goal 3)
	bool can_checkout() const; //if cart empty cannot checkout
	void checkout() const; //MVP 2.4 (print a receipt of all items purchased and the total cost to the user)
	bool is_empty() const;
	void print_items() const; //print the users current cart
	double get_total() const;
};