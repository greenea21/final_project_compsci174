#include <iostream>
#include <string>
#include "menu.h"
#include "store.h"

using std::cout; using std::endl;

int main() {
	menu menu;
	menu.start();

	menu.print_store_items();

	return 0;
}