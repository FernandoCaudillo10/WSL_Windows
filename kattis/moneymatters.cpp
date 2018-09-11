#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
	int id;
	Node *parent;
	unordered_set<Node*> children;
	Node(){
		parent = this;
	}
};



int main(){
	int friends, fships;
	cin >> friends >> fships;
	
	vector<int> owed(friends);
	for(auto & elem : owed){
		cin >> elem;	
	}

	vector<Node*> nodes(friends, nullptr);

	for(auto & elem : nodes){
		elem = new Node();
	}
	
	for(int i=0; i<fships; i++){
		int num1, num2;
		cin >> num1 >> num2;
		nodes[num1]->id = num1;
		nodes[num2]->id = num2;
		nodes[num1]->children.insert(nodes[num2]);
	}
	
	for(auto & elem : nodes){
		for(auto i = elem->children.begin(); i != elem->children.end(); i++)
			cout << (*i)->id << " ";
		cout << ";";
	}

	return 0;
}
