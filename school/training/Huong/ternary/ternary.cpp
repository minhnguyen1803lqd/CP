#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define vi vector < int > 

const int inf = 1e9 + 7;
const int esf = 1e-9;

int _a, _c;
vi a, c, res;

vi getTer(int a) {
    vi res;
    while (a) {
        res.push_back(a % 3);
        a /= 3;
    }
    return (res);
}

void balance() {
    while (a.size() != c.size()) {
        if (a.size() < c.size()) {
            a.push_back(0);
        } else {
            c.push_back(0);
        }
    }
}

int getVal(int a, int c) {
    if (a == 0 and c == 0) return (0);
    if (a == 0 and c == 1) return (1);
    if (a == 0 and c == 2) return (2);
    if (a == 1 and c == 1) return (0);
    if (a == 1 and c == 2) return (1);
    if (a == 1 and c == 0) return (2);
    if (a == 2 and c == 2) return (0);
    if (a == 2 and c == 0) return (1);
    if (a == 2 and c == 1) return (2);
}

int getDec(vi a) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += (a[i] * pow(3, i));
    }
    return (res);
}

int main() {
    fileInput("ternary");
    fast;
    cin >> _a >> _c;

    a = getTer(_a);
    c = getTer(_c);
    balance();
    
    for (int i = 0; i < a.size(); i++) {
        res.push_back(getVal(a[i], c[i]));
    }

    // for (int i = 0; i < res.size(); i++) {
    //     cout << res[i] << " ";
    // }
    // cout << endl;

    cout << (getDec(res)) << endl;
    
    return (0);
}