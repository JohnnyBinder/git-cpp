#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

bool IsPalindromePermutation(string& input) {
	transform(input.begin(), input.end(), input.begin(), ::tolower);

	map<char, int> histogram;

	bool is_even = input.size() % 2 == 0;

	for (int i = 0; i != input.size() / 2; ++i) {
		++histogram[input[i]];	
	}

	for (int i = input.size(); i != input.size() / 2; --i) {
		--histogram[input[i]];
	}

	int sum = 0;
	for (auto& item : histogram)
		sum += item.second;

	if (is_even) {
		return sum == 0;
	} 
	else {
		return sum == 1;
	}
}

int main() {
	string input;
	getline(cin, input);

	 if (IsPalindromePermutation(input))
		 cout << "True\n";
	 else
		 cout << "False\n";
}
