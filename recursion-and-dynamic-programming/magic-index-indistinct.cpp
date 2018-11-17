#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int FindMagicIndex(const vector<int>& array, const int start, const int end) {
	if (end < start) return -1;

	int index = (start + end) / 2;
	if (array[index] == index)
		return index;

	int new_end = min(index-1, array[index]);	
	int new_start = FindMagicIndex(array, start, new_end);
	
	if (new_start != -1)
		return new_start;

	new_start = max(index+1, array[index]);
	new_end = FindMagicIndex(array, new_start, end);

	return new_end;
}

int FindMagicIndex(const vector<int>& array) {
	if (array.size() == 0)
		return -1;
	return FindMagicIndex(array, 0, array.size()-1);
}

int main() {
	vector<int> v{-10, -5, 1, 2, 2, 3, 4, 7, 9, 12, 13};

	int magic_index = FindMagicIndex(v);

	if (magic_index == -1)
		cout << "No magic index was found" << endl;
	else 
		cout << "Magic index: " << magic_index << endl;
}
