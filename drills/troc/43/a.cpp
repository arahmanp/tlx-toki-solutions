// problem: A - Dikit Lagi Lulus
// contest: TROC #43
// tags: ad-hoc
// status: -

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    int countAscSeq = 1;
    int sep;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] > a[i + 1]) {
            countAscSeq++;
            sep = i + 1;
        }
    }

    return 0;
}