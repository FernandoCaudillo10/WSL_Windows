#include <iostream>
#include "bag.hpp"

int main(){
	
	caudillo::Bag b;
	
	bool quit = false;	
	while(!quit){
		char choice;
		std::cout << "Please enter a choice from these options: \n";
		std::cout << "1.To add a new item to a bag\n2.Erase one value\n3.Erase all copies of one value\n4.Add two bags using +\n5.Add two bags using +=\n6.Display a bags contents\n7. Subtract a bag class\nq  Quit test program\n";
		
		std::cout << "---->";
		std::cin >> choice;
		std::cout << "\n";

		caudillo::Bag::value_type temp;
		caudillo::Bag::size_type index;
		caudillo::Bag c;
		c.add(2); c.add(5); c.add(1); c.add(10);
		switch(choice){
			case '1':
				std::cout << "Enter a value to add ----> ";
				std::cin >> temp;
				b.add(temp);
				std::cout << std::endl;
				break;
			case '2':
				std::cout << "Enter the index of which you want to erase -----> ";
				std::cin >> index;
				b.erase(index);
				std::cout << std::endl;
				break;
			case '3':
				std::cout << "Enter value to erase recursively ---> ";
				std::cin >> temp;
				b.eraseAll(temp);
				std::cout << std::endl;
				break;
			case '4':
				b = b + c;
				std::cout << "Added a bag [2,5,1,10] to your current bag...\n";
				break;
			case '5':
				b += c;
				std::cout << "Added a bag [2,5,1,10] to your current bag...\n";
				break;
			case '6':
				b.display();
				break;
			case '7':
				b = b - c;
				std::cout << "Subtracted the bag[2,5,1,10] from your current bag...\n";
				break;
			default:
				quit = true;
				break;
		}
	}

	return 0;
}
