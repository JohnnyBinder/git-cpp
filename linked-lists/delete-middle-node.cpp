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
	cout << "Enter items of list separated by spaces: ";

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

// Will delete node k+1 or kth from head node
void DeleteMiddleNode(Node* n, int k) {
	for (int i = 0; i < k; ++i) {
		n = n->next;
	}

	*n = *(n->next);
	delete n->next;
}

int main() {
	auto head = InitializeList();

	PrintList(head);

	DeleteMiddleNode(head, 3);

	PrintList(head);
}
