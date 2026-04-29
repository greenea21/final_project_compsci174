#pragma once
#include <vector>
#include "item.h"

using std::vector;

struct store {
	vector<item> store_inventory; //array of items sold by the store

	void initialize_items();
	void print_items() const;
	bool can_purchase(int index) const;
	int find_item_index(const std::string& key) const;
};