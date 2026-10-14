#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vi> a(n, vi(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) cin >> a[i][j];

	int mul_row = 1;
	int mul_col = 1;
	int sign_x;
	if(m % 2 == 0) mul_row = -1;
	if(n % 2 == 0) mul_col = -1;
	
	ll curr = 0;
	for(int i = 0; i < n; i++) {
		ll sum = 0;
		int ml = mul_row;
		for(int j = 0; j < m; j++) {
			if(a[i][j] != -1)
				sum += ml * mul_col * (ll)a[i][j];
			else
				sign_x = ml * mul_col;
			ml *= -1;
		}
		curr += sum;
		mul_col *= -1;
	}

	// cout << curr << ' ' << sign_x << '\n';
	
	if(curr == 0) cout << "YES" << '\n' << curr << '\n';
	else if(curr > 0  && sign_x > 0) cout << "NO\n";
	else if(curr < 0 && sign_x < 0) cout << "NO\n";
	else cout << "YES\n" << abs(curr) << '\n';

	return 0;
}

