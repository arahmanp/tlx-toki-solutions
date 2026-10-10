#include <ios>
#include <iostream>
#include <vector>

typedef long long ll;

const ll M = 998'244'353;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<ll> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    ll res = 1;
    for(auto el : a) {
        res = (res * el) % M;
    }

    std::cout << res << '\n';

    return 0;
}