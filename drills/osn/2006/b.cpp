// problem: B - Tebak Lagu
// contest: OSN Informatika 2006
// tags: implementation
// status: Accepted

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> symToNum = {
    {"c.", 1},
    {"c#", 2},
    {"d.", 3},
    {"d#", 4},
    {"e.", 5},
    {"f.", 6},
    {"f#", 7},
    {"g.", 8},
    {"g#", 9},
    {"a.", 10},
    {"a#", 11},
    {"b.", 12},
};

vector<string> numToSym = {
    "",
    "c.",
    "c#",
    "d.",
    "d#",
    "e.",
    "f.",
    "f#",
    "g.",
    "g#",
    "a.",
    "a#",
    "b.",
};

int getNum(string s) {
    if(islower(s[0])) return symToNum[s];
    else {
        s[0] = tolower(s[0]);
        return symToNum[s] + 12;
    }
}

string getStr(int i) {
    if(i <= 12) return numToSym[i];
    else {
        string ori = numToSym[i - 12];
        ori[0] = toupper(ori[0]);
        return ori;
    }
}

string parse(string s) {
    string res = "";
    int len = s.length();
    int minVal = 1e9;
    for(int i = 0; i < len - 1; i += 2) {
        minVal = min(minVal, getNum(s.substr(i, 2)));
    }
    int diff = minVal - 1;
    for(int i = 0; i < len - 1; i += 2) {
        string now = s.substr(i, 2);
        int nowNum = getNum(now);
        nowNum -= diff;
        res += getStr(nowNum);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n;

    cin >> s >> n;

    s = parse(s);

    vector<string> song(n);
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        song[i] = parse(tmp);
    }

    bool found = false;
    int ans;
    for(int i = 0; i < n && !found; i++) {
        auto res = song[i].find(s);
        if(res != string::npos) {
            found = true;
            ans = i + 1;
        }
    }

    if(!found) cout << '#' << '\n';
    else cout << ans << '\n';

    return 0;
}