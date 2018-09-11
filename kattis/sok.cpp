#include <iostream>

using namespace std;

int main(){
	
	double orange, apple, pinnaple;

	double rat_o, rat_a, rat_p;
	
	cin >> orange >> apple >> pinnaple >> rat_o >> rat_a >> rat_p;
	
	double total = rat_o + rat_a + rat_p;
	rat_o = rat_o / total;
	rat_a = rat_a / total;
	rat_p = rat_p / total;

	while(orange > 0.0001 && apple > 0.0001 && pinnaple > 0.0001){
		orange *= rat_o;
		apple *= rat_a;
		pinnaple *= rat_p;	
		cout << orange << " " << apple << " " << pinnaple << endl;
	
	}

	cout << orange << " " << apple << " " << pinnaple << endl;

	return 0;
}
