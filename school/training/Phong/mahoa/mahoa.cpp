#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int query, n;
string s;

string mod(string s) {
    return ('*' + s);
}

string divide(string s, int left, int right) {
    if (left > right) return ("");
    if (right == left) return (s);
    if (left + 1 == right) return(s);
    int mid = (left + right) / 2;
    string l, r;
    for (int i = left; i < mid; i++) l += s[i];
    for (int i = mid + 1; i <= right; i++) r += s[i];
    string l_tmp = divide(l, left, mid - 1);
    string r_tmp = divide(r, mid + 1, right);
    return (s[mid] + l_tmp + r_tmp);
}

main() {
    fileInput("mahoa");
    cin >> query;
    while (query--) {
        cin >> n >> s;
        s = mod(s);
        cout << divide(s, 1, n) << endl;
    }
}
