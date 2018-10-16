#include <iostream>
#include <string>

using namespace std;

bool OneAway(const string& s1, const string& s2) {
	// The subtraction has to be casted to an int or the < operator will compare size_t < int, thereby converting the int
	// to a positive value which will cause problems if the subtraction returns a size_t value of 0
	if (static_cast<int>(s1.size() - s2.size()) > 1 || static_cast<int>(s1.size() - s2.size()) < -1) {
		return false;
	}

	int i = 0; // Index for string s1
	int j = 0; // Index for string s2
	bool edit_found = false;

	while (i != s1.size() && j != s2.size()) {
		if (s1[i] != s2[j]) {
			if (edit_found)
				return false;
			edit_found = true;
			if (s1[i+1] == s2[j])
				++i;
			else if (s1[i] == s2[j+1])
				++j;
		}
		++i;
		++j;
	}

	if (!edit_found) {
		if (i == s1.size() && j != s2.size())
			return true;

		if (i != s1.size() && j == s2.size())
			return true;
	}

	return edit_found;
}

int main() {
	string s1;
	cin >> s1;

	string s2;
	cin >> s2;

	if (OneAway(s1, s2))
		cout << "True" << endl;
	else
		cout << "False" << endl;
}
