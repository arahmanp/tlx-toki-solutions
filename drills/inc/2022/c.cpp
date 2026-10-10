// problem: C - Powers of Two
// contest: INC 2022
// tags: ad-hoc, string-hashing
// status: Accepted

#include <ios>
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;

    std::unordered_set<std::string> n;

    while(q--) {
        std::string sign;
        int x;
        std::cin >> sign >> x;

        std::string tmp = sign + std::to_string(x);
        int nextNum = x + 1;
        while(n.contains(tmp)) {
            n.erase(tmp);
            tmp = sign + std::to_string(nextNum);
            nextNum++;
        }

        std::string tmpOpposite = "";
        tmpOpposite += ((tmp[0] == '+') ? '-' : '+') + tmp.substr(1);

        if(n.contains(tmpOpposite)) n.erase(tmpOpposite);
        else n.insert(tmp);

        if(n.empty()) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}