#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e4 + 10;
const int oo = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define vi vector < int >

int n, val[N];
vi p;

void Print(vi x) {
    for (int i = 0; i < x.size(); i++) cout << val[x[i]]; cout << endl;
}

bool Check(vi p) {
    int n = p.size() - 1;
    if (!(val[p[0]] <= val[p[1]] + val[p[n]])) return (false);
    if (!(val[p[n]] <= val[p[0]] + val[p[n - 1]])) return (false);
    for (int i = 1; i < n; i++) {
        if (!(val[p[i]] <= val[p[i - 1]] + val[p[i + 1]])) return (false);
    }
    return (true);
}

int main() {
    FileOpen;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= n; i++) p.push_back(i);
    do {
        if (Check(p)) {
            Print(p);
            return (0);
        }
    } while (next_permutation(p.begin(), p.end()));
}
