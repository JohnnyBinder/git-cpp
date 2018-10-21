#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int val) : val{val}, next{nullptr} {}
};

Node* InitializeList() {
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
	while (n) {
		cout << n->val << " -> ";
		n = n->next;
	}
	cout << endl;
}

void RemoveDups(Node* n) {
	if (n == nullptr)
		throw "List is empty";
	if (n->next == nullptr)
		return;

	map<int, bool> hash_table;
	Node* runner = n;
	hash_table[runner->val] = true;
	runner = runner->next;

	while (runner) {
		if (!hash_table[runner->val]) {
			hash_table[runner->val] = true;
			n->next = runner;
			n = n->next;
		}
		runner = runner->next;
	}

	n->next = nullptr;
}


int main() {
	Node* head = InitializeList();
	PrintList(head);

	RemoveDups(head);
	PrintList(head);
}
