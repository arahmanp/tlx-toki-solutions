#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string label;
    cin >> label;

    int n;
    cin >> n;

    string s;
    cin >> s;

    ll a, b, res;
    a = b = res = 0;

    for(auto c : s) {
        if(c == '1') a++;
        else if(c == '2') b += a;
        else if(c == '3') res += b;
    }

    cout << res << '\n';

    return 0;
}

