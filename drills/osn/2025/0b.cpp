#include <algorithm>
#include <ios>
#include <iostream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int maxval = 0;
    std::unordered_map<int, int> freq;
    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        freq[x]++;
        maxval = std::max(maxval, x);
    }

    long long ans = 0;
    for(const auto &[x, cntx] : freq) {
        for(int y = 2 * x; y <= maxval; y += x) {
            if(freq.contains(y)) {
                if(y < (x ^ y)) ans += ((long long)cntx * freq[y]);
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}