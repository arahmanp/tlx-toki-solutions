#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<int> maxMod(m, -1);
    for(auto el : a) maxMod[el % m] = std::max(maxMod[el % m], el);

    long long res = -1;
    for(auto el : a) {
        if(el % m == 0) {
            res = std::max(res, (long long)el * 2);
            continue;
        }

        int aiM = el % m;
        int ajM = m - aiM;

        if(maxMod[ajM] == -1) continue;

        res = std::max(res, (long long)el + maxMod[ajM]);
    }

    std::cout << res << '\n';

    return 0;
}
