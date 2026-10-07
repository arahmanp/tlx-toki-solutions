// problem: 2C - Pola Segitiga
// contest: OSN Informatika 2009
// tags: implementation
// status: Accepted

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int gap1 = 1;
    int gap2 = 2 * (n / 2) - 3;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) cout << ' ';
        if(i < n / 2) {
            if(i == 0) cout << '*';
            else {
                cout << '*';
                for(int j = 0; j < 2 * i - 1; j++) cout << ' ';
                cout << '*';
            }
        } else if(i == n / 2) {
            for(int j = 0; j < n; j++) cout << '*';
        } else if(i == n - 1) {
            for(int j = 0; j < 2 * n - 1; j++) cout << '*';
        } else {
            int cp = i;
            cout << '*';
            for(int j = 0; j < gap1; j++) cout << ' ';
            cout << '*';
            for(int j = 0; j < gap2; j++) cout << ' ';
            cout << '*';
            for(int j = 0; j < gap1; j++) cout << ' ';
            cout << '*';
            gap1 += 2;
            gap2 -= 2;
        }
        cout << '\n';
    }

    return 0;
}