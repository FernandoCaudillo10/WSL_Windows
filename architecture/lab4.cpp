#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

string convertBin(int num){
	if(num < 0) num *= -1;

	string bin;
	while(num != 0){
		bin += to_string(num % 2);
		num /= 2;
	}
	reverse(bin.begin(), bin.end());
	return bin;
}

int main(){
	
	const int floatingPoint = 15;
		
	int num;
	cout << "Enter an integer value: ";
	cin >> num;
	
	if(num > pow(2,8)-1 || num < pow(2, 8) * -1){
		cout << "Sorry, " << num << " is to large to be stored in our system\n";
		return 0;
	}

	string bin = convertBin(num);
	string exp = convertBin(bin.size() + floatingPoint);
	
	for(int i=bin.size(); i<8; i++) bin += '0';

	cout << "Here is how " << num << " is stored as floating-point in memory:\n";
	cout << "------------------------\n";
	cout << "| " << (num < 0) << " | " << exp << " | " << bin << " |\n";
	cout << "------------------------\n";

	return 0;
}
