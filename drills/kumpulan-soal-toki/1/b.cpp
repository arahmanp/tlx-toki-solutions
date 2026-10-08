#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	
	int t;
	cin >> t;
	
	while(t--) {
		char p, q;
		int x, y;
		cin >> p >> x >> q >> y;
		
		if(p == 'A') {
			if(q == 'A') swap(a[x - 1], a[y - 1]);
			else swap(a[x - 1], b[y - 1]);
		} else {
			if(q == 'B') swap(b[x - 1], b[y - 1]);
			else swap(b[x - 1], a[y - 1]);
		}
	}
	
	for(auto el : a) cout << el << ' ';
	cout << '\n';
	for(auto el : b) cout << el << ' ';
	
	return 0;
}