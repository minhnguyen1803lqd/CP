#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define iii pair < ii, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 5e4 + 7;

struct node {
    int val, org, mark;
};

int n, k;
node a[N];
int f[N];

bool cmp(node a, node b) {
    return (a.val < b.val);
}

bool cmp2(node a, node b) {
    return (a.org < b.org);
}

int main() {
    fileInput("teamk");
    fast;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].org = i;
        a[i].mark = 0;
    }
    sort(a + 1, a + 1 + n, cmp);
    int id = 0;
    for (int i = 1; i <= n / k; i++) {
        for (int j = 1; j <= k; j++) {
            a[++id].mark = i;
        }
    }
    sort(a + 1, a + 1 + n, cmp2);
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].org << " " << a[i].mark << " " << a[i].val << endl;
    // }
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i].mark >= a[j].mark) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++) ans = min(ans, n - f[i]);
    cout << ans << endl;

    return (0);
}