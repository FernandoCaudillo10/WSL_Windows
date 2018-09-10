#include "bag.hpp"
#include <unordered_map>

namespace caudillo{
	Bag::Bag(){
		used = 0;
		current = 0;	
	}
	void Bag::add(value_type input){
		if(current == CAP) return;

		data[current] = input;
		current++;
		used++;
	}
	void Bag::erase(size_type index){
		if(index < 0 || index > CAP) return;

		for(int i=index; i<used-1; i++){
			data[i] = data[i+1];
			used--;
			current--;
		}
	}
	void Bag::eraseAll(value_type input){
		for(int i=0; i<used; i++){
			if(data[i] == input)
				erase(i);
		}
	}

	Bag operator+(const Bag& a, const Bag& b){
		Bag c;

		for(int i=0; i<a.used; i++){
			c.add(a.data[i]);
		}

		for(int i=0; i<b.used; i++){
			c.add(b.data[i]);
		}
		return c;	
	}
	Bag& operator+=(Bag& a, const Bag& b){
		for(int i=0; i<b.used; i++){
			a.add(b.data[i]);
		}
	}
	Bag operator-(const Bag& a, const Bag& b){
		Bag c;
		
		std::unordered_map<Bag::value_type, Bag::size_type> m;
		for(int i=0; i<a.used; i++){
			if(m.find(a.data[i]) != m.end()){
				m[a.data[i]]++;
			}
			else
				m[a.data[i]] = 0;
		}
		for(int i=0; i<b.used; i++){
			if(m.find(b.data[i]) != m.end()){
				m[b.data[i]]++;
			}
			else
				m[b.data[i]] = 0;
		}

		for(auto i = m.begin(); i != m.end(); i++){
			if((*i).second == 1)
				c.add((*i).first);
			std::cout << (*i).first << " " << (*i).second << std::endl;
		}
		return c;
	}

	void Bag::display(){
		std::cout << "[ ";
		for(int i=0; i<used; i++){
			std::cout << data[i] << ", ";
		}
		std::cout << "] \n";
	}
}
