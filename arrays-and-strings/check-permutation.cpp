#include <iostream>
#include <string>

using namespace std;

bool CheckPermutation(const string& first, const string& second) {
	if (first.size() != second.size())
		return false;

	int hashtable[256]{};

	for (const auto& letter : first) {
		++hashtable[letter];
	}

	for (const auto& letter : second) {
		--hashtable[letter];
	}

	for (int i = 0; i < 256; ++i) {
		if (hashtable[i] != 0)
			return false;
	}

	return true;
}

int main() {
	string first_input;
	cin >> first_input;

	string second_input;
	cin >> second_input;

	if (CheckPermutation(first_input, second_input))
		cout << "Permutation exists.\n";
	else
		cout << "Permutation doesn't exist.\n";
}
