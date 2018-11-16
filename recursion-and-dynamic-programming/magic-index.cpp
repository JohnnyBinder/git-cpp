#include <iostream>
#include <vector>

using namespace std;

int FindMagicIndex(const vector<int>& arr, const int start, const int end) {
	if (arr.size() == 0)
		return -1;

	if (end < start)
		return -1;

	int index = (start + end) / 2;

	if (arr[index] == index)
		return index;
	if (arr[index] > index)
		return FindMagicIndex(arr, start, index-1);
	else 
		return FindMagicIndex(arr, index+1, end);
}

int FindMagicIndex(const vector<int>& arr) {
	return FindMagicIndex(arr, 0, arr.size()-1);
}

int main() {
	vector<int> v;

	int num;
	while (cin >> num)
		v.push_back(num);

	int magic_index = FindMagicIndex(v);

	if (magic_index == -1)
		cout << "The list contains no magic index\n";
	else
		cout << "Found magic index: " << magic_index << endl;
}
