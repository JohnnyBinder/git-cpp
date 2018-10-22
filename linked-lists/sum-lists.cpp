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
	cout << "Enter values of list separated by spaces: ";

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

Node* SumLists(Node* l1, Node* l2) {
	if (!l1 && !l2)
		throw "Lists can't be empty";

	int carry = 0;
	int sum = l1->val + l2->val;

	if (sum > 9) {
		carry = 1;
		sum -= 10;
	}

	Node* head = new Node{sum};
	Node* list = head;

	l1 = l1->next;
	l2 = l2->next;

	while (l1 || l2) {
		if (l1 && l2)
			sum = l1->val + l2->val + carry;
		else if (l1)
			sum = l1->val + carry;
		else if (l2)
			sum = l2->val + carry;

		if (sum > 9) {
			carry = 1;
			sum -= 10;
		} else {
			carry = 0;
		}

		list->next = new Node{sum};
		list = list->next;

		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}

	if (carry)
		list->next = new Node{1};

	return head;
}

int main() {
	Node* l1 = InitializeList();
	Node* l2 = InitializeList();

	PrintList(l1);
	PrintList(l2);

	Node* sum_lists = SumLists(l1, l2);

	PrintList(sum_lists);
}
