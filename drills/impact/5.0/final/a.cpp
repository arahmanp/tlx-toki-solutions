// problem: A - 01
// contest: IMPACT 5.0 - Final
// tags: ad-hoc, bitwise
// status: Accepted

#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    for(auto el : a) {
        if(el % 2 == 0) std::cout << "TIDAK\n";
        else std::cout << "YA\n";
    }

    return 0;
}