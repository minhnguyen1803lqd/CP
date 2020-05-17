#include <bits/stdc++.h>

#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define int long long

const int inf = 1e9 + 7;

using namespace std;

int query, n, k;

int search(int k) {
    int l = 1, r = 1000000000;
    int ans = inf;
    while (l <= r) {
        int mid = (l + r) / 2;
        if ((n * mid - mid) >= k) {
            r = mid - 1;
            ans = min(ans, mid);
        } else {
            l = mid + 1;
        }
    }
    return (ans);
}

main() {
    fileInput("c");
    fast;
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> n >> k;
        // do {
        //     id++;
        //     tmp = n * id - id;
        // } while (tmp < k);
        int id = search(k);
        int tmp = n * id - id;
        cerr << id << endl;
        cerr << tmp << endl;
        cout << (n * id - 1) - (tmp - k) << endl;
    }
    return (0);
}