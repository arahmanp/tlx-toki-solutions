#include <ios>
#include <iostream>

typedef long long ll;

bool isHasPositiveArea(ll x, ll y, ll z) {
    ll i = x + y + z;

    if(i <= 2 * x) return false;
    if(i <= 2 * y) return false;
    if(i <= 2 * z) return false;

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll x, y, z;
    std::cin >> x >> y >> z;

    if(x != y && y != z && x != z) {
        std::cout << "Tidak\n";
        return 0;
    }

    if(!isHasPositiveArea(x, y, z)) {
        std::cout << "Tidak\n";
        return 0;
    }

    ll ab, c;
    if(x == y) {
        ab = x;
        c = z;
    } else if(y == z) {
        ab = y;
        c = x;
    } else {
        ab = x;
        c = y;
    }

    if(c - ab != 1) {
        std::cout << "Tidak\n";
    } else {
        std::cout << "Ya\n";
    }

    return 0;
}