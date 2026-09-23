// problem: B - Djo, Djo, dan Wadidaw
// contest: TROC #28
// tags: constructive
// status: Accepted

#include <algorithm>
#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char c[3] = {'w', 'a', 'd'};

    int n;
    std::cin >> n;

    int half = (n - 1) / 2;

    std::string half_str = "";
    for(int i = 1; i <= half; i++) {
        half_str += c[i % 3];
    }

    std::string res = half_str + 'i';

    std::reverse(half_str.begin(), half_str.end());

    res += half_str;

    std::cout << res << '\n';

    return 0;
}