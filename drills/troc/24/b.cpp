// problem: B - Pembalikan Rangkap
// contest: TROC #24
// tags: ad-hoc
// status: Accepted

// Catatan penyelesaian: perhatikan batasan variabel! jangan sampai overflow!

#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<ll> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    if(n == 2) {
        std::cout << a[0] - a[1] << '\n';
        return 0;
    }

    ll opt_1 = 0, opt_2 = 0, multiplier = 1;
    for(int i = 0; i < n; i++) {
        opt_1 += (multiplier * a[i]);
        opt_2 += (-1 * multiplier * a[i]);
        multiplier *= -1;
    }

    ll res = std::max(opt_1, opt_2);

    std::cout << res << '\n';

    return 0;
}