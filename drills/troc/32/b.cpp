// problem: B - Robot Pusing
// contest: TROC #32
// tags: ad-hoc
// status: Accepted

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

    std::vector<int> v;
    bool hasSeq = false;
    int countOne = 0;
    int zeroIdx;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            zeroIdx = i;
            break;
        }
    }

    for(int i = 0; i <= n; i++) {
        if(a[(zeroIdx + i) % n] == 0 && hasSeq) {
            v.push_back(countOne);
            countOne = 0;
            hasSeq = false;
        } else if(a[(zeroIdx + i) % n] == 1) {
            hasSeq = true;
            countOne++;
        }
    }

    long long res = 0;

    for(auto el : v) res += (((long long)el * (el + 1)) / 2);

    std::cout << res << '\n';

    return 0;
}