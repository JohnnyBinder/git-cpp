#include <iostream>
#include <stack>
#include <initializer_list>

using namespace std;

class MinStack {
	stack<int> min_stack_;
	stack<int> normal_stack_;

public:
	MinStack(initializer_list<int> list) {
		for (auto num : list) {
			this->push(num);
		}
	}

	void push(const int data) {
		if (min_stack_.empty()) 
			min_stack_.push(data);
		else if (data < min_stack_.top())
				min_stack_.push(data);

		normal_stack_.push(data);
	}

	int pop() {
		if (normal_stack_.empty())
			throw "Stack is empty";

		if (normal_stack_.top() == min_stack_.top())
			min_stack_.pop();

		int data = normal_stack_.top();
		normal_stack_.pop();

		return data;
	}

	int min() const {
		return min_stack_.top();
	}

	friend ostream& operator<<(ostream& out, MinStack& s) {
		out << endl;

		while (!s.normal_stack_.empty()) {
			if (s.normal_stack_.top() == s.min_stack_.top()) {
				out << "Normal: " << s.normal_stack_.top();
				out << " Min: "  << s.min_stack_.top() << endl;
				s.min_stack_.pop();	
				s.normal_stack_.pop();
			} else {
				out << "Normal: " <<  s.normal_stack_.top() << endl;
				s.normal_stack_.pop();
			}
		}

		out << endl;

		return out;
	}
};

int main() {
	MinStack ms{5, 1, 4, 7, 0, 2, 9, -1};

	cout << ms << endl;
}
