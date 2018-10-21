#include <iostream>
#include <cstring>

using namespace std;

void URLify(char input[], int length) {
	int actual_length = strlen(input);

	--length;
	for (int i = actual_length-1; i != 0; --i) {
		if (input[length] != ' ')
			input[i] = input[length];
		else {
			input[i] = '0';
			input[--i] = '2';
			input[--i] = '%';
		}
		--length;
	}
}

int main() {
	char input[] = {"Mr John Smith    "};
	int length = 13;

	URLify(input, length);
	
	cout << input << endl;
}
