#include <ios>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    int x1 = d - a;
    int x2 = e - b;
    int x3 = f - c;

    if((x1 % 2 == 0 && x2 % 2 == 0 && x3 % 2 == 0) || 
        (x1 % 2 != 0 && x2 % 2 != 0 && x3 % 2 != 0)) std::cout << 0 << '\n';
    else std::cout << 1 << '\n';

    return 0;
}