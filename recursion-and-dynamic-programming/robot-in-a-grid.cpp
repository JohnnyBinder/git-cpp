#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool getPath(vector<vector<bool>>& maze, const int col, const int row, vector<pair<int,int>>& path) {
	if (col < 0 || row < 0 || !maze[col][row])
		return false;

	bool is_at_origin = (col == 0) && (row == 0);

	if (is_at_origin || getPath(maze, col, row-1, path) || getPath(maze, col-1, row, path)) {
		path.push_back(make_pair(col, row));	
		return true;
	}

	return false;
}

vector<pair<int,int>> getPath(vector<vector<bool>>& maze) {
	if (maze.size() == 0)
		return vector<pair<int,int>>{};

	vector<pair<int,int>> path;
	
	getPath(maze, maze.size()-1, maze[0].size()-1, path);

	return path;
}

int main() {
	vector<vector<bool>> maze;

	int cols, rows;
	cin >> cols >> rows;

	for (int i = 0; i < cols; ++i) {
		vector<bool> temp;
		for (int j = 0; j < rows; ++j) {
			bool input;
			cin >> input;
			temp.push_back(input);
		}
		maze.push_back(temp);
	}

	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}

	auto path = getPath(maze);

	cout << "The path is: " << endl;
	for (const auto& point : path) {
		cout << "x: " << point.second << ", y: " << point.first << endl;
	}
}
