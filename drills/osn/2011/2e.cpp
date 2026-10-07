// problem: 2E - Kursi Konser
// contest: OSN Informatika 2011
// tags: implementation
// status: Accepted

#include <algorithm>
#include <ios>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::tuple<int, int, int>> kursi;
    kursi.reserve(n * m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            kursi.push_back({i, j, i + j});
        }
    }

    std::sort(kursi.begin(), kursi.end(), [] (std::tuple<int, int ,int> a, std::tuple<int, int, int> b) {
        auto [xa, ya, dista] = a;
        auto [xb, yb, distb] = b;
        if(dista != distb) return dista < distb;
        return xa < xb;
    });

    auto [solx, soly, soldist] = kursi[k - 1];

    std::cout << solx << ' ' << soly << '\n';

    return 0;
}