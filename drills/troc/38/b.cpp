#include <ios>
#include <iostream>

typedef long long ll;

ll f(ll n) {
    ll res = 1;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            int c = 0;
            while(n % i == 0) {
                c++;
                n /= i;
                res *= i;
            }
            if(c % 2 != 0) res *= i;
        }
    }
    if(n > 1) res *= n * n;
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::cin >> n;

    std::cout << f(n) / n << '\n';

    return 0;
}