#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

typedef std::tuple<std::string, int, int> p;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<p> pList(n);
    for(int i = 0; i < n; i++) {
        std::string s;
        int a, b, c, d;
        std::cin >> s >> a >> b >> c >> d;
        pList[i] = {s, a + c, b + d};
    }

    std::sort(pList.begin(), pList.end(), [] (const p &p1, const p &p2) {
        auto [p1n, p1s, p1d] = p1;
        auto [p2n, p2s, p2d] = p2;

        if(p1s != p2s) return p1s > p2s;
        else {
            if(p1d != p2d) return p1d < p2d;
            else return p1n < p2n;
        }
    });

    for(auto [name, s, p] : pList) {
        std::cout << name << '\n';
    }
}