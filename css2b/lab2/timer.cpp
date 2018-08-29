#include "timer.h"

namespace caudillo_timer{

	Timer::Timer(){

	}
	Timer::Timer(ui_type hour, usi_type minutes, usi_type seconds){
		this->hours = hour;
		this->minutes = minutes;
		this->seconds = seconds;
	}
	void Timer::setHours(ui_type hours){
		assert(hours >= 0);
		this->hours = hours;
	}
	void Timer::setMinutes(usi_type minutes){
		assert(minutes >= 0);
		this->hours += minutes / 60;
		this->minutes = minutes % 60;
	}
	void Timer::setSeconds(usi_type seconds){
		assert(seconds >= 0);
		this->minutes += seconds / 60;
		this->seconds = seconds % 60;
	}

	Timer Timer::operator+(const Timer &a) const{
		Timer ans;
		ans.hours = this->hours + a.hours;
		ans.setMinutes(this->minutes + a.minutes);
		ans.setSeconds(this->seconds + a.seconds);
		ans.setMinutes(this->minutes);
		return ans;
	}
	bool Timer::operator<(const Timer &a) const{
		if(this->hours != a.hours){
			return this->hours < a. hours;
		}
		else if(this->minutes != a.minutes){
			return this->minutes < a.minutes;
		}
		return this->seconds < a.seconds;
	}
	bool Timer::operator>(const Timer &a) const{
		if(this->hours != a.hours){
			return this->hours > a. hours;
		}
		else if(this->minutes != a.minutes){
			return this->minutes > a.minutes;
		}
		return this->seconds > a.seconds;
	}
	bool Timer::operator==(const Timer &a) const{
		if(this->hours != a.hours){
			return this->hours == a.hours;
		}
		else if(this->minutes != a.minutes){
			return this->hours == a.hours;
		}
		return this->seconds == a.seconds;
	}
	std::ostream& operator<<(std::ostream& os, const Timer& a){
		os << a.hours << std::endl;
		os << a.minutes << std::endl;
		os << a.seconds << std::endl;
		return os;
	}
}
