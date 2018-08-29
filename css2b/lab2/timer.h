#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <cassert>

namespace caudillo_timer{
	class Timer{
		public:
			typedef unsigned int ui_type;
			typedef unsigned short int usi_type;
			
			Timer();
			Timer(ui_type hour, usi_type minutes, usi_type seconds);
			
			ui_type getHours() const { return hours; }
			usi_type getMinutes() const { return minutes; }
			usi_type getSeconds() const { return seconds; }
			
			void setHours(ui_type hours);
			void setMinutes(usi_type minutes);
			void setSeconds(usi_type seconds);
			
			Timer operator+(const Timer &a) const;	
			bool operator<(const Timer &a) const;
			bool operator>(const Timer &a) const;
			bool operator==(const Timer &a) const;
			
			friend std::ostream& operator<<(std::ostream& os, const Timer& a);
				
		private:
			ui_type hours;
			usi_type minutes;
			usi_type seconds;


	};
}
#endif
