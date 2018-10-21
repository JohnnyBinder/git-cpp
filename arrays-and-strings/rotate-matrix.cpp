#include <iostream>
#include <vector>

using namespace std;

template <class T>
void RotateMatrix(vector<vector<T>>& m) {
	// Check that m is square
	
	int size = m.size() - 1;

	for (int layer = 0; layer != m.size() / 2; ++layer) {
		for (int i = layer; i != size - layer; ++i) {
			int temp = m[layer][i];
			m[layer][i] = m[size-i][layer];
			m[size-i][layer] = m[size-layer][size-i];
			m[size-layer][size-i] = m[i][size-layer];
			m[i][size-layer] = temp;
		}
	}
}

template <class T>
void PrintMatrix(const vector<vector<T>>& m) {
	for (int row = 0; row != m.size(); ++row) {
		for (int col = 0; col != m[0].size(); ++col) {
			cout << m[row][col] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	vector<vector<int>> m = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	PrintMatrix(m);
	cout << endl;

	RotateMatrix(m);

	PrintMatrix(m);
	cout << endl;
}
