#include <iostream>
#include <string>

using namespace std;

string Compress(const string& s) {
	int count{}; // Counts number of chars
	string compressed; // Compressed string
	int i{}; // Used to indexing string
	char current{s[0]}; // Keeps track of current letter

	while (i != s.size()) {
		if (current == s[i]) {
			++count;
		} 
		else {
			compressed += current + to_string(count);
			current = s[i];
			count = 1;
		}
		++i;
	}

	// Because i will hit the size of s and the last iteration in
	// the while loop which causes the appending to the string will
	// not happen
	compressed += current + to_string(count);

	if (s.size() <= compressed.size())
		return s;
	return compressed;
}

int main() {
	string input;
	cin >> input;

	cout << Compress(input) << endl;
}
