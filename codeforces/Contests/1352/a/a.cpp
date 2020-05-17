#include <bits/stdc++.h>

#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

const int inf = 1e9 + 7;

using namespace std;

int query, x;
vector < int > a;

int main() {
    fileInput("a");
    fast;
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> x;
        int tmp = x;
        int cnt = 0;
        while (tmp != 0) {
            cnt++;
            a.push_back(tmp % 10);
            tmp /= 10;
        }
        int id = 0;
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > 0) {
                ans++;
            }
        }
        cout << ans << endl;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            id++;
            if (a[i] != 0)
            {
                cout << a[i];
                for (int j = 1; j <= cnt - id; j++)
                {
                    cout << 0;
                }
                cout << " ";
            }
            }
        cout << endl;
        a.clear();
    }
    return (0);
}