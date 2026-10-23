#include <algorithm>
#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    int n = s.size(), cnt_b = 0;
    for(auto c : s) {
        if(c == 'B') cnt_b++;
    }

    int ans = std::min(n / 4, cnt_b / 3);

    std::cout << ans << '\n';

    return 0;
}