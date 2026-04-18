#pragma once
#include <vector>
#include "item.h"

using std::vector;

struct cart {
	vector<item> cart_inventory;//use the 'vector' class here to create an array that can dynamically grow/shrink (Stretch goal 1)

	vector<item> get(); //return the cart array (MVP 2.2 -- View the items in their cart)
	void add_item(item item); //check if store quanitity exists, remove n items from store, add n items to cart_inventory.
	void remove_item(item item);
	void sort(); //(Stretch goal 3)
	void checkout() const; //MVP 2.4 (print a receipt of all items purchased and the total cost to the user)
	void view() const; //print the users current cart
};