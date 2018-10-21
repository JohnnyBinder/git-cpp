#include <iostream>
#include <memory>

using namespace std;

struct Node {
	int data_;
	unique_ptr<Node> left_;
	unique_ptr<Node> right_;

	Node(const int data) : data_{data} {}
};

using Tree = unique_ptr<Node>;

Tree& Insert(Tree& t, Node&& node) {
	if (!t) 
		return t = make_unique<Node>(move(node));
	else if (t->data_ < node.data_)
		return Insert(t->left_, move(node));
	else if (t->data_ > node.data_)
		return Insert(t->right_, move(node));
	else
		// no work to do.
		return t;
}

unique_ptr<Node> Insert(Node* root, Node* node) {
	if (!root)
		root = node;
	else if (root->data_ < node->data_)

}

int main() {
	Tree t = make_unique<Node>(5);

	if (Insert(t, Node{4}) == t)
		cerr << "Already exists\n";
	else
		cout << "New value inserted\n";
	if (Insert(t, Node{4}) == t)
		cerr << "Already exists\n";
	else
		cout << "New value inserted\n";
}
