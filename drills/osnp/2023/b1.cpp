#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    ll sum_a = 0;
    ll sum_b = 0;
    for(int i = 0; i < n; i++) {std::cin >> a[i]; sum_a += (ll)a[i];}
    for(int i = 0; i < m; i++) {std::cin >> b[i]; sum_b += (ll)b[i];}

    std::sort(b.begin(), b.end());

    ll ans = 0;
    while((sum_a * m <= sum_b * n) && (b.size() > 1)) {
        int taken = b.back();
        int n_taken = 0;

        while((b.back() == taken) && (b.size() > 1)) {
            n_taken++;
            b.pop_back();
        }

        sum_a += ((ll)taken * n_taken);
        n += n_taken;
        sum_b -= ((ll)taken * n_taken);
        m -= n_taken;
        ans += ((ll)taken * n_taken);
    }

    if(sum_a * m <= sum_b * n) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans << '\n';
    }

    return 0;
}