#include <iostream>
#include <string>

using namespace std;

bool IsUnique(const string& s) {
	int hashtable[256]{};

	for (const auto& letter : s) {
		++hashtable[letter];

		if (hashtable[letter] > 1)
			return false;
	}

	return true;
}

int main() {
	string input;
	getline(cin, input);

	if (IsUnique(input))
		cout << "All characters are unique\n";
	else
		cout << "Characters are not all unique\n";
}
