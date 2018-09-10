#ifndef BAG_H
#define BAG_H

#include <cstdlib>
#include <iostream>

namespace caudillo{
	
	class Bag{
		public:
			typedef int value_type;
			typedef std::size_t size_type;
			static const size_type CAP = 30;
			Bag();
			void add(value_type input);
			void erase(size_type index);
			void eraseAll(value_type input);

			friend Bag operator+(const Bag& a, const Bag& b);
			friend Bag& operator+=(Bag& a, const Bag& b);
			friend Bag operator-(const Bag& a, const Bag& b);

			void display();
			
		private:
			value_type data[CAP];
			size_type used;
			size_type current;

	};

}

#endif
