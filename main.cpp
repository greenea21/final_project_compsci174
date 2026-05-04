//STRETCH GOALS COMPLETED
//1: Vector instead of array for cart
//2: Remove item from cart
//6: Sales tax
//7: Receipt output to file
//9: Switch statement instead of if-else chain
//10: Safeguard against malicious input

//------------------------------------------------------------------------//

//program starts here with menu.start()
//menu handles all user input and program flow
//menu manages cart and store objects
//store handles inventory and stock
//cart handles cart contents, totals, checkout
//probably didn't need a menu class; could've just put it here

#include "menu.h"

int main() {
	menu menu;
	menu.start();
	
	return 0;
}