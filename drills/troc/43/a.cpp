// problem: A - Dikit Lagi Lulus
// contest: TROC #43
// tags: ad-hoc
// status: Accepted

#include <ios>
#include <iostream>
#include <vector>

bool isAscending(const std::vector<int> &v) {
    int len = v.size();
    for(int i = 0; i < len - 1; i++) {
        if(v[i] > v[i + 1]) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    std::vector<int> tmp;
    tmp.reserve(n - 1);
    for(int i = 0; i < n; i++) {
        if(i == x - 1) continue;
        else tmp.push_back(a[i]);
    }

    if(isAscending(tmp)) std::cout << 1 << '\n';
    else std::cout << 0 << '\n';

    return 0;
}