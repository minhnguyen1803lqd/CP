/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

string s, ans = "";
string hr, t;

int StringToNum(string s) {
    int res = int(s[0]) - int('0');
    res = res * 10 + int(s[1]) - int('0');
    return (res);
}

int main() {
    FileOpen;
    cin >> s;
    for (int i = 0; i < 2; i++) hr += s[i];
    for (int i = s.length() - 2; i < s.length(); i++) t += s[i];
    if (t == "AM") {
        if (hr == "12") {
            cout << "00";
            for (int i = 2; i < s.length() - 2; i++) {
                cout << s[i];
            }
        } else {
            for (int i = 0; i < s.length() - 2; i++) {
                cout << s[i];
            }
        }
    } else {
        int res = StringToNum(hr);
        if (res != 12) res += 12;
        if (res < 10) cout << "0";
        cout << res;
        for (int i = 2; i < s.length() - 2; i++) cout << s[i];
    }
}
