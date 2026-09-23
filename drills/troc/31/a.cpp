// problem: A - besar ahli
// contest: TROC #31
// tags: constructive, string
// status: Accepted

#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s, t;
    std::cin >> s >> t;

    std::cout << s + t << '\n';

    return 0;
}