#include <ios>
#include <iostream>
#include <numeric>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, m;
    std::cin >> n >> m;

    if(m % n != 0) {
        std::cout << -1 << '\n';
        return 0;
    }

    ll ans = 0;

    while(n != m) {
        ll x = m / n;
        ll y = std::gcd(x, n);
        if(y == 1) {
            std::cout << -1 << '\n';
            return 0;
        }
        n *= y;
        ans++;
    }

    std::cout << ans << '\n';
}