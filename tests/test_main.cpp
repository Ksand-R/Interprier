#include <gtest.h>
#include "Expr.h"
#include "List.h"
#include <iostream>
#include "st_and_queue.h"

int main(int argc, char **argv) {
	
	char Inp[25];
	cin >> Inp;
	expression input(Inp);
	cout << input.counting() << endl;

	/*::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();*/
	return 0;
}
