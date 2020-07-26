//  TODO: solve this problem
#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 1e3 + 7;

int n;
int x[N], cnt[N];
vector < vector < int > > ans;

bool isPrime(int x) {
    for (int i = 2; i <= (int)sqrt(x) + 1; i++) if (x % i == 0) return (false);
    return(true);
}

void backTrack(int id) {
    if (id == 2 * n + 1) {
        for (int i = 1; i <= 2 * n - 1; i++) if (!isPrime(x[i] + x[i + 1])) return;
        vector < int > res;
        for (int i = 1; i <= 2 * n; i++) res.push_back(x[i]);
        ans.push_back(res);
    } else {
        if (id == 2 * n) {
            for (int i = 2; i <= 2 * n; i++) {
                if (cnt[i]) {
                    if (isPrime(i + x[1])) {
                        x[id] = i;
                        cnt[i]--;
                        backTrack(id + 1);
                        cnt[i]++;
                    }
                }
            }
        } else {
            for (int i = 2; i <= 2 * n; i++) {
                if (cnt[i]) {
                    if (isPrime(i + x[id - 1])) {
                        x[id] = i;
                        cnt[i]--;
                        backTrack(id + 1);
                        cnt[i]++;
                    }
                }
            }
        }
    }
}

main() {
    fileInput("pcircle");
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) cnt[i] = 1;
    x[1] = 1;
    backTrack(2);
    cout << ans.size() << endl;
    for (int k = 0; k < ans.size(); k++) {
        vector < int > res = ans[k];
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}