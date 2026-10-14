#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int max_bit_len = 0;
    ll tmp = v.back();
    while(tmp > 0) {
        max_bit_len++;
        tmp >>= 1;
    }

    for(auto el : v) cout << bitset<64>(el).to_string() << '\n';

    vector<int> even_bit;

    for(int i = max_bit_len - 1; i >= 0; i--) {
        ll x = 0;
        for(int j = 0; j < n; j++) {
            x ^= (v[j] & (1LL << i));
        }
        if(x == 0) even_bit.push_back(i);
    }

    for(auto el : even_bit) cout << el << '\n';

    ll x = v.back();

    for(auto bit : even_bit) x ^= (1LL << bit);

    ll res = 0;
    for(int i = 0; i < n - 1; i++) res ^= v[i];

    res ^= x;

    cout << res << '\n' << max_bit_len << '\n';

    return 0;
}

