#include <iostream>
#include <string>

using namespace std;

void PermutationHelper(const string& s, string permutation, size_t index) {
	if (index == s.size()) {
		cout << permutation << endl;
		return;
	}

	for (size_t i = 0; i <= permutation.size(); ++i) {
		string new_permutation = permutation.substr(0, i) + string(1, s[index]) + permutation.substr(i, string::npos);
		PermutationHelper(s, new_permutation, index+1);
	}
}

void PermutationWithoutDups(const string& s) {
	string permutation;
	PermutationHelper(s, permutation, 0);
}

int main() {
	cout << "Enter a string without duplicate characters: ";
	string input;
	cin >> input;

	PermutationWithoutDups(input);
}
