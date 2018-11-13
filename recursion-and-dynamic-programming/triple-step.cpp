#include <iostream>

using namespace std;

int TripleStep(const int n, int* memo) {
	if (n < 0)
		return 0;

	if (n == 0)
		return 1;

	if (memo[n] != -1) {
		return memo[n];
	}

	memo[n] = TripleStep(n-1, memo) + TripleStep(n-2, memo) + TripleStep(n-3, memo); 

	return memo[n];
}

int TripleStep(const int n) {
	int* memo = new int[n+1];

	for (int i = 0; i < n+1; ++i) {
		memo[i] = -1;
	}

	return TripleStep(n, memo);
}

int main() {
	int n;
	cin >> n;

	cout << "Count: " << TripleStep(n) << endl;
}
