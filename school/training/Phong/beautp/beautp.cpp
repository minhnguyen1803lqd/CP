#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

int n, ans = 0;
int a[N], cnt[N];

int main() {
    fileInput("beautp");
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    while (1) {
        int count = 0;
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i]) {
                cnt[i]--;
                count++;
            }
        }
        if (count) ans += count - 1;
        else break;
    }
    cout << ans << endl;
    return (0);
}