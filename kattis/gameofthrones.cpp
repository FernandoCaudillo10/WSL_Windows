#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void logic(bool undo, int steps, int &child, int n, vector<int> &pastOutcomes){
	//cout << "hello: " << undo << " " << steps << " " << child << " " << endl;	
	if(undo){
		for(int i=0; i<steps; i++)
			pastOutcomes.pop_back();
		child = pastOutcomes[pastOutcomes.size()-1];
		return;
	
	}
	else if(steps < 0){
		child = (child+steps+n) % n;
	}
	else{	
		child = (steps+child) % n;
	}

	pastOutcomes.push_back(child);
}

int main(){

	int n, k;
	while( cin >> n){

		cin >> k;
		
		string op;
		
		vector<int> pastOutcomes(1,0);
		int child = 0;
			
		while(k-->0){
			cin >> op;	
			int steps;	
			if(op == "undo"){
				cin >> steps;
			}
			else{
				
				steps = stoi(op);
			}
			
			logic( (op == "undo"), steps, child, n, pastOutcomes);
				
		}

		cout << pastOutcomes[pastOutcomes.size()-1] << endl;
	}

	return 0;
}
