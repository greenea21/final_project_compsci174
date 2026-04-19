#pragma once
#include <vector>
#include "item.h"

using std::vector;

struct store {
	vector<item> store_inventory; //array of items sold by the store

	void initialize_items(); //fill up the store_inventory array with items from a text file
	void print_items() const; //MVP 2.3 (View all items (and their prices and stock) available for purchase)
	bool can_purchase(int index) const; //find item in array; if item <= 0 return false; else return true;
	int find_index(std::string key) const;
};