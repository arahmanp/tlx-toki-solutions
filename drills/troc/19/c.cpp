#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    std::cin >> k;

    std::vector<int> on, off;
    for(int i = 0; i < 31; i++) {
        if((k & (1 << i)) == 0) off.push_back(1 << i);
        else on.push_back(1 << i);
    }

    int first = (1 << 30) - 1;
    std::vector<int> res;

    res.push_back(first);

    int counter = 1;
    int on_idx = 0;
    int off_idx = 0;
    while((on_idx < (int)on.size()) && (off_idx < (int)off.size())) {
        if(counter % 2 == 0) {
            first -= off[off_idx++];
            res.push_back(first);
        } else {
            first -= on[on_idx++];
            res.push_back(first);
        }
        counter++;
    }

    std::cout << res.size() << '\n';
    for(auto el : res) {
        std::cout << el << ' ';
    }

    std::cout << '\n';

    return 0;
}