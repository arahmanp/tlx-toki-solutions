#include <deque>
#include <ios>
#include <iostream>
#include <string>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::deque<int> dq;

    while(n--) {
        std::string op;
        std::cin >> op;

        if(op == "push_back" || op == "push_front") {
            int x;
            std::cin >> x;

            if(op == "push_back") dq.push_back(x);
            else dq.push_front(x);
        } else {
            if(op == "pop_back") dq.pop_back();
            else dq.pop_front();
        }
    }
    for(auto el : dq) std::cout << el << '\n';
}
