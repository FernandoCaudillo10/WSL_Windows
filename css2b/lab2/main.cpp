#include <iostream>
#include "timer.h"

int main(){
	
	caudillo_timer::Timer a(2, 31, 45), b(1, 59, 45), c(2, 31, 45);
	
	std::cout << (a == b) << std::endl;
	std::cout << (a == c) << std::endl;

	std::cout << (c > b) << std::endl;
	c = a + b;
	std::cout << (c < b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << std::endl;
	std::cout << c << std::endl;

	return EXIT_SUCCESS;
}
