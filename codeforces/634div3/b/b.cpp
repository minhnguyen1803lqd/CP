#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int query, n, a, b;

int countDiff(string s, int subStringLimitLength) {
    for (int i = s.length() - 1; i >= s.length() - subStringLimitLength; i--) {
        
    }
}

string Create(int limitLength, int subStringLimitLength, int distinctChar) {
    string res;
    for (int i = 1; i <= limitLength - subStringLimitLength; i++) res += char(1 + int("0"));
    for (int i = 1; i <= distinctChar; i++) res += char(i + int("0"));
    
    while (res.length() < limitLength) {
        int diff = countDiff(res, subStringLimitLength);
    }

    return (res);
}

int main() {
    FileOpen;
    srand(time(NULL));
    cin >> query;
    for (int qq = 0; qq < query; qq++) {
        cin >> n >> a >> b;
        string res = Create(n, a, b);
        cout << res << endl;
    }
}
