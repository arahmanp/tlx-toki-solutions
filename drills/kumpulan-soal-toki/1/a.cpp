#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	unordered_set<int> duplicate;
	vector<int> res;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(duplicate.count(x) == 0) {
			res.push_back(x);
			duplicate.insert(x);
		}
	}
	
	for(auto el : res) cout << el << '\n';
	
	return 0;
}