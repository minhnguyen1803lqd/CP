#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int k;
int n;
vector < int > ans;

main() {
    fileInput("luckynum");
    cin >> k;
    n = log2(k + 1);
    int tmp = k + 1, cnt = 0;
    while (tmp != 0) {
        ans.push_back(tmp % 2);
        tmp = tmp / 2;
        cnt++;
        if (cnt == n) break;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (ans[i] == 0) cout << 4;
        else cout << 7;
    }
    cout << endl;
}
