#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int num) : val{num}, next{nullptr} {}
};

Node* InitializeList() {
	cout << "Enter list items separated by spaces: ";

	string input;
	getline(cin, input);

	stringstream ss(input);
	int num;
	ss >> num;
	Node* head = new Node(num);
	Node* n = head;

	while (ss >> num) {
		n->next = new Node(num);
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

Node* KthToLast(Node* n, const int k) {
	if (!n)
		throw "List is empty";

	Node* runner = n;

	for (int i = 0; i < k; ++i) {
		n = n->next;
	}

	while (n) {
		n = n->next;
		runner = runner->next;
	}

	return runner;
}

int main() {
	auto head = InitializeList();

	PrintList(head);

	auto kth_to_last = KthToLast(head, 4);

	cout << "The value of the kth to last node is: " << kth_to_last->val << endl;
}
