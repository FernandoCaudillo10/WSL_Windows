#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <cstdlib>
#include <cassert>

namespace caudillo_sequence {
	
	class Sequence{
		
		public:
			typedef double value_type;
			typedef std::size_t size_type;
			static const size_type CAPACITY = 30;

			Sequence();

			void start();
			void advance();
			void insert(const value_type& entry);
			void attach(const value_type& entry);
			void remove_current();
			
			void remove_front();
			void push_front(const value_type& entry);
			void push_end(const value_type& entry);
			void end();

			friend Sequence operator+(const Sequence& s1, const Sequence& s2);
			friend Sequence operator+=(const Sequence& s1, const Sequence& s2);
			value_type operator[](size_type index) const;

			size_type size() const { return used; }
			bool is_item() const { return current_index != used; }
			value_type current() const { return data[current_index]; }

		private:

			value_type data[CAPACITY];
			size_type used;
			size_type current_index;

	};
	
}

#endif
