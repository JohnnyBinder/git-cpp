#include <iostream>
#include <string>

using namespace std;

bool StringRotation(const string& s1, const string& s2) {
	if (s1.size() != s2.size())
		return false;

	const string s1_doubled = s1 + s1;
	
	return s1_doubled.find(s2) != string::npos;
}

int main() {
	string s1;
	cin >> s1;

	string s2;
	cin >> s2;

	if (StringRotation(s1, s2))
		cout << "True" << endl;
	else
		cout << "False" << endl;
}
