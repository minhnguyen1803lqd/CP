#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e2 + 7;

ll query;
ll f[N][N];

int main() {
    fileInput("bcdiv");
    fast;
    FOR(i, 1, 25) {
        f[i][1] = 1;
    }
    FOR(i, 2, 25) {
        FOR(j, 1, 25) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j] * j;
        }
    }
    scanf("%lld", &query);
    FOR(qq, 1, query) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%lld\n", f[n][k]);
    }
    return (0);
}

/*
 * gọi f(i, j) là số cách chia n người thành k nhóm, mõi nhóm ít nhất 1 người
 * nhận xét: có 2 trường hợp lớn:
 * + chia người thử i vào 1 nhóm riêng và n - 1 người còn lại vào k - 1 nhóm
 * => f(i, j) = f[i - 1][j - 1] + 1;
 * + chia i - 1 người còn lại thành j nhóm và xếp người thứ i vào j nhóm đó => có j cách chia
 * => f(i, j) = f[i - 1][j] * j
 * bài toán con: i người chia thành 1 nhóm thì có 1 cách.
 */