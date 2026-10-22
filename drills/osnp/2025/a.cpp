#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    std::cin >> s;

    int n = s.size();

    std::vector<int> cnt_o(n, 0), cnt_s(n, 0), cnt_n(n, 0), cnt_p(n, 0);

    if(s[0] == 'O') cnt_o[0] = 1;
    if(s[0] == 'S') cnt_s[0] = 1;
    if(s[0] == 'N') cnt_n[0] = 1;

    for(int i = 1; i < n; i++) {
        cnt_o[i] = cnt_o[i - 1];
        cnt_s[i] = cnt_s[i - 1];
        cnt_n[i] = cnt_n[i - 1];
        if(s[i] == 'O') cnt_o[i] += 1;
        if(s[i] == 'S') cnt_s[i] += 1;
        if(s[i] == 'N') cnt_n[i] += 1;
    }

    if(s[n - 1] == 'P') cnt_p[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--) {
        cnt_p[i] = cnt_p[i + 1];
        if(s[i] == 'P') cnt_p[i] += 1;
    }

    int ans = -1;
    for(int i = 0; i < n - 1; i++) {
        if(cnt_o[i] != 0 && cnt_s[i] != 0 && cnt_n[i] != 0 && cnt_p[i + 1] != 0) {
            ans = std::max(ans, cnt_o[i] + cnt_s[i] + cnt_n[i] + cnt_p[i + 1]);
        }
    }

    std::cout << ans << '\n';
}