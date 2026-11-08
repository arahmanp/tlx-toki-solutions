#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

bool check(int x, int n, int p, const std::vector<int> &k, const std::vector<std::vector<int>> &m) {
    std::vector<int> best(n, 1e9);

    for(int i = 0; i < n; i++) {
        int l = 0;
        int r = k[i] - 1;
        bool found = false;

        while(l < r) {
            if(m[i][l] + m[i][r] >= x) {
                found = true;
                best[i] = std::min(best[i], m[i][l] + m[i][r]);
                r--;
            } else {
                l++;
            }
        }

        if(!found) return false;

    }

    int sum = 0;
    for(auto el : best) sum += el;

    return (sum <= p);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, p;
    std::cin >> n >> p;

    std::vector<int> k(n);
    std::vector<std::vector<int>> m(n);
    for(int i = 0; i < n; i++) {
        std::cin >> k[i];

        m[i].reserve(k[i]);

        for(int j = 0; j < k[i]; j++) {
            int a;
            std::cin >> a;
            m[i].push_back(a);
        }

        std::sort(m[i].begin(), m[i].end());
    }

    int lb = 0;
    int ub = 20000;
    int ans = -1;
    while(lb <= ub) {
        int mid = lb + (ub - lb) / 2;

        bool ok = check(mid, n, p, k, m);

        if(ok) {
            ans = mid;
            lb = mid + 1;
        } else {
            ub = mid - 1;
        }
    }

    std::cout << ans << '\n';
}