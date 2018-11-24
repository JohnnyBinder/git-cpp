#include <iostream>
#include <stack>

using namespace std;

void load_tower(stack<int>& tower, const int num_of_discs) {
	for (int i = num_of_discs; i >= 1; --i)
		tower.push(i);
}

void print_tower(stack<int> tower) {
	while (!tower.empty()) {
		cout << tower.top() << " ";
		tower.pop();
	}
	cout << endl;
}

void solve(int num_of_discs, stack<int>& from_tower, stack<int>& buffer_tower, stack<int>& to_tower) {
	if (num_of_discs == 1) {
		int temp = from_tower.top();
		from_tower.pop();
		to_tower.push(temp);
		return;
	}

	solve(num_of_discs-1, from_tower, to_tower, buffer_tower);
	solve(1, from_tower, buffer_tower, to_tower);
	solve(num_of_discs-1, buffer_tower, from_tower, to_tower);
}

int main() {
	cout << "Enter number of discs: ";
	int num_of_discs;
	cin >> num_of_discs;

	stack<int> tower1; 
	stack<int> tower2;
	stack<int> tower3;

	load_tower(tower1, num_of_discs);

	solve(num_of_discs, tower1, tower2, tower3);
	
	cout << "Tower 1: ";
	print_tower(tower1);

	cout << "Tower 2: ";
	print_tower(tower2);

	cout << "Tower 3: ";
	print_tower(tower3);
}
