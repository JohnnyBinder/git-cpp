#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int val) : val{val}, next{nullptr} {}
};

Node* InitializeList() {
	cout << "Please enter numbers separated by spaces: ";
	string input;
	getline(cin, input);

	stringstream ss(input);
	int num;
	ss >> num;

	Node* head = new Node{num};
	Node* n = head;

	while (ss >> num) {
		n->next = new Node{num};
		n = n->next;
	}

	return head;
}

void PrintList(Node* n) {
	cout << endl;
	while (n) {
		cout << n->val << " -> ";
		n = n->next;
	}
	cout << endl;
}

bool IsPalindrome(Node* head) {
	int count = 0;
	Node* n = head;
	
	while (n) {
		n = n->next;
		++count;
	}

	bool is_odd = count % 2 == 1;
	
	map<int,int> hash_table;

	n = head;

	for (int i = 0; i < count / 2; ++i) {
		++hash_table[n->val];
		n = n->next;
	}

	if (is_odd)
		n = n->next;

	while (n) {
		--hash_table[n->val];

		if (hash_table[n->val] < 0)
			return false;

		n = n->next;
	}

	return true;
}

int main() {
	Node* head = InitializeList();

	PrintList(head);

	if (IsPalindrome(head))
		cout << "True" << endl;
	else
		cout << "False" << endl;
}
