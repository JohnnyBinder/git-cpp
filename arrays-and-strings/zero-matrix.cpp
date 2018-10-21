#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void PrintMatrix(const vector<vector<int>>& m) {
	for (int row = 0; row != m.size(); ++row) {
		for (int col = 0; col != m[0].size(); ++col) {
			cout << setw(4) << m[row][col] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

bool CheckFirstRowForZero(vector<vector<int>>& m) {
	for (int col = 0; col != m[0].size(); ++col) {
		if (m[0][col] == 0)
			return true;
	}
	return false;
}

bool CheckFirstColForZero(vector<vector<int>>& m) {
	for (int row = 0; row != m.size(); ++row) {
		if (m[row][0] == 0)
			return true;
	}
	return false;
}

void ZeroOutCols(vector<vector<int>>& m) {
	for (int col = 1; col != m[0].size(); ++col) {
		if (m[0][col] == 0) {
			for (int row = 1; row != m.size(); ++row) {
				m[row][col] = 0;
			}
		}
	}
}

void ZeroOutRows(vector<vector<int>>& m) {
	for (int row = 1; row != m.size(); ++row) {
		if (m[row][0] == 0) {
			for (int col = 1; col != m[0].size(); ++col) {
				m[row][col] = 0;
			}
		}
	}
}

void ZeroMatrix(vector<vector<int>>& m) {
	bool first_row_has_zero = CheckFirstRowForZero(m);
	bool first_col_has_zero = CheckFirstColForZero(m);

	for (int row = 1; row != m.size(); ++row) {
		for (int col = 1; col != m[0].size(); ++col) {
			if (m[row][col] == 0) {
				m[0][col] = 0;
				m[row][0] = 0;
			}
		}
	}

	ZeroOutCols(m);
	ZeroOutRows(m);

	if (first_row_has_zero)
		// Zero out first row
		for (int col = 0; col != m[0].size(); ++col)
			m[0][col] = 0;
	
	if (first_col_has_zero)
		// Zero out first col
		for (int row = 0; row != m.size(); ++row) 
			m[row][0] = 0;
}

int main() {
	vector<vector<int>> m = {
		{1, 0, 2, 3, 4, 0},
		{8, 5, 6, 0, 7, 8},
		{9, 10, 11, 12, 13, 14},
		{15, 16, 3, 17, 18, 18}
	};

	PrintMatrix(m);

	ZeroMatrix(m);

	PrintMatrix(m);
}
