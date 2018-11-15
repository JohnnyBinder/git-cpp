#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

bool getPath(vector<vector<bool>>& maze, const int col, const int row, vector<pair<int,int>>& path, set<pair<int,int>>& failed_points) {
	if (col < 0 || row < 0 || !maze[col][row])
		return false;

	auto point = make_pair(col, row);

	if (failed_points.find(point) != failed_points.end())
		return false;

	bool is_at_origin = (col == 0) && (row == 0);

	if (is_at_origin || getPath(maze, col, row-1, path, failed_points) || getPath(maze, col-1, row, path, failed_points)) {
		path.push_back(point);	
		return true;
	}

	failed_points.insert(point);
	return false;
}

vector<pair<int,int>> getPath(vector<vector<bool>>& maze) {
	if (maze.size() == 0)
		return vector<pair<int,int>>{};

	vector<pair<int,int>> path;
	set<pair<int,int>> failed_points;
	
	getPath(maze, maze.size()-1, maze[0].size()-1, path, failed_points);

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
