#include <ios>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a;
    std::cin >> a;

    if(a % 2 == 0) std::cout << a / 2 << '\n';
    else {
        if(((a + 1) / 2) % 2 == 0) std::cout << -1 << '\n';
        else std::cout << (a + 1) / 2 << '\n';
    }

    return 0;
}