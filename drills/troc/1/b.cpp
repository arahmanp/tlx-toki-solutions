#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, r, v;
    std::cin >> n >> r >> v;

    std::vector<int> w(n);
    for(int i = 0; i < n; i++) std::cin >> w[i];

    double ans = -1.0;
    for(auto w_i : w) {
        if(w_i == v) {
            std::cout << -1 << '\n';
            return 0;
        }
        double t_i = (double)r / abs(v - w_i);
        ans = std::max(ans, t_i);
    }

    std::cout << std::fixed << std::setprecision(9) << ans << '\n';
}