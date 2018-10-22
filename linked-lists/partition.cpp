#include <iostream>
#include <string>
#include <sstream>

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
	cout << endl;
	while (n) {
		cout << n->val << " -> ";
		n = n->next;
	}
	cout << endl;
}

Node* partition(Node* head, int k) {
	Node* new_head;
	Node* n = head;

	while (n->next) {
		if (n->next->val < k) { 
			new_head = n->next;
			n->next = n->next->next;
			new_head->next = head;
			head = new_head;
		} else {
			n = n->next;
		}
	}

	return head;
}

int main() {
	Node* head = InitializeList();

	PrintList(head);

	head = partition(head, 3);

	PrintList(head);
}
