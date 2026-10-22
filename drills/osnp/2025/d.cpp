#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, int>> range_a;
    int l = -1;
    int cnt_b = 0;
    for(int r = 0; r < n; r++) {
        if(s[r] == 'A' && l == -1) l = r;
        if(s[r] == 'B' && l != -1) {
            range_a.push_back({l, r - 1});
            l = -1;
        }
        if(s[r] == 'B') cnt_b++;
    }

    if(l != -1) range_a.push_back({l, n - 1});

    if((int)range_a.size() <= k) {
        std::cout << cnt_b << '\n';
        return 0;
    }

    int n_r = range_a.size();
    std::vector<int> gaps;
    gaps.reserve(n_r - 1);
    for(int i = 0; i < n_r - 1; i++) {
        auto [li, ri] = range_a[i];
        auto [ln, rn] = range_a[i+1];
        gaps.push_back(ln - ri - 1);
    }

    int erased = n_r - k;
    std::sort(gaps.begin(), gaps.end());

    for(int i = 0; i < erased; i++) cnt_b -= gaps[i];

    std::cout << cnt_b << '\n';
}