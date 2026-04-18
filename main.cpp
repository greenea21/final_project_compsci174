#include <iostream>
#include <string>
#include "menu.h"
#include "store.h"

using std::cout; using std::endl;

int main() {
	menu menu;
	menu.start();
	//menu.show_options(); //create unique functions for each context/set of options
	switch (menu.get_user_choice("\nPlease enter your choice (digit):\n1. Show store items\n2. Exit")) {
	case 1:
		cout << "You selected: Show store items" << endl;
		menu.print_store_items();
	case 2:
		cout << "You selected: Exit" << endl;
		exit(1);
	}

	//menu.print_store_items();

	return 0;
}