// problem: I - Ini Plus atau Minus?
// contest: Arkavidia 9.0 - Penyisihan CP
// tags: implementation, math
// status: Accepted

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if((k > 0 && n < k) || (k < 0 && abs(k) >= n)) {
        cout << "NO\n";
        return 0;
    }

    if((n - abs(k)) % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}