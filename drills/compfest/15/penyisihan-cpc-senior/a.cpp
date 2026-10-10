#include <algorithm>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int best = 1e9;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        best = std::min(best, abs(a[i]));
    }

    std::cout << best << '\n';

    return 0;
}