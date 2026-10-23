#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];

    std::sort(a.begin(), a.end());

    if(n >= 2 && a[0] == 1 && a[1] == 2) {
        std::cout << 1 << ' ';
        for(int i = 2; i < n; i++) std::cout << a[i] << ' ';
        std::cout << 2 << '\n';
    } else {
        for(auto el : a) std::cout << el << ' ';
        std::cout << '\n';
    }
}