#include <iostream>
#include <vector>

using namespace std;

void PowerSet(const vector<int>& set, vector<vector<int>>& subsets, vector<int>& subset, const size_t index) {
	if (index == set.size()) {
		subsets.push_back(subset);	
		return;
	}
	else {
		subset[index] = 0;
		PowerSet(set, subsets, subset, index+1);
		subset[index] = 1;
		PowerSet(set, subsets, subset, index+1);
	}
}

vector<vector<int>> PowerSet(const vector<int>& set) {
	if (set.size() == 0)
		cout << "Set contains a single empty set" << endl;

	vector<vector<int>> subsets;
	vector<int> subset(set.size(), 0);
	
	PowerSet(set, subsets, subset, 0);

	return subsets;
}

int main() {
	vector<int> v{1, 2, 3};
	
	auto subsets = PowerSet(v);

	for (const auto set : subsets) {
		cout << "Set: ";
		for (size_t i = 0; i < set.size(); ++i) {
			if (set[i] == 1)
				cout << v[i] << " ";
		}
		cout << endl;
	}
}
