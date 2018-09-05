#include "Sequence.hpp"

namespace caudillo_sequence{

	Sequence::Sequence(){
		used = 0;
		current_index = -1;
	}

	void Sequence::start(){
		current_index = 0;
	}
	void Sequence::advance(){
		if(current_index == size()) return;

		current_index++;
	}
	void Sequence::insert(const Sequence::value_type& entry){
		if(size() >= CAPACITY) return;
		
		for(int i=current_index; i<size(); i++){
			data[i+1] = data[i];
		}
		data[current_index] = entry;
		used++;
	}
	void Sequence::attach(const Sequence::value_type& entry){
		if(size() >= CAPACITY) return;
		
		if(current_index == size()){ push_end(entry); return; }

		current_index++;
		insert(entry);

	}
	void Sequence::remove_current(){
		if(current_index == size()){
			used--;
			current_index--;
		}

		for(int i=current_index; i<size(); i++){
			data[i] = data[i+1];
		}
	}

	void Sequence::remove_front(){
		current_index = 0;
		remove_current();
	}
	void Sequence::push_front(const Sequence::value_type& entry){
		current_index = 0;
		insert(entry);
	}
	void Sequence::push_end(const Sequence::value_type& entry){
		if(size() >= CAPACITY) return;
		
		current_index++;
		used++;
		
		data[current_index] = entry;	
	}
	void Sequence::end(){
		current_index = size();
	}

	Sequence operator+(const Sequence& s1, const Sequence& s2){
		Sequence result;

		for(int i=0; i<s1.size(); i++){
			result.attach(s1[i]);
		}
		for(int i=0; i<s2.size(); i++){
			result.attach(s2[i]);
		}

		return result;
	}
	Sequence operator+=(const Sequence& s1, const Sequence& s2){
		Sequence result;

		for(int i=0; i<s1.size(); i++){
			result.attach(s1[i]);
		}
		for(int i=0; i<s2.size(); i++){
			result.attach(s2[i]);
		}

		return result;
	}
	
	Sequence::value_type Sequence::operator[](Sequence::size_type index) const{
		assert(index < size());
		return data[index];
	}

}
