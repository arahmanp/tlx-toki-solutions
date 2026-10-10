// problem: C - Galaksi
// contest: TROC #27
// tags: ad-hoc, constructive
// status: Accepted

#include <ios>
#include <iostream>
#include <utility>

typedef long long ll;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    if(n > m) std::swap(n, m);

    std::cout << (ll)(n - 1) * m << '\n';

    return 0;
}