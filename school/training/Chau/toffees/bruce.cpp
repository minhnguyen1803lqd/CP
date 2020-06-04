#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".ans").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e5 + 7;

int n;
char q[N];
int a[N];

int main() {
    fileInput("toffees");
    fast;
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        cin >> q[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        if (q[i] == 'L') {
            a[i] = max(a[i] + 1, a[i + 1] + 1);
        } else if (q[i] == 'R') {
            a[i + 1] = max(a[i] + 1, a[i + 1] + 1);
        } else if (q[i] == 'R') {
            if (a[i] == a[i + 1]) continue;
            else if (a[i] > a[i + 1]) {
                a[i + 1] += (a[i + 1] - a[i]);
            } else if (a[i] < a[i + 1]) {
                a[i] += (a[i + 1] - a[i]);
            }
        }
        for (int j = i - 1; j >= 1; j--) {
            if (q[j] == 'L') {
                if (a[j] > a[j + 1]) continue;
                else if (a[j] < a[j + 1]) {
                    a[j] += a[j + 1] - a[j] + 1;
                } else if (a[j] == a[j + 1]) {
                    a[j] += 1;
                }
            } else if (q[j] == 'R') {
                if (a[j] < a[j + 1]) continue;
                else if (a[j] > a[j + 1]) {
                    a[j + 1] += a[j] - a[j + 1] + 1;
                } else if (a[j] == a[j + 1]) {
                    a[j + 1] += 1;
                }
            } else if (q[j] == '=') {
                if (a[j] == a[j + 1]) continue;
                else if (a[j] > a[j + 1]) a[j + 1] += a[j] - a[j + 1];
                else if (a[j] < a[j + 1]) a[j] += a[j + 1] - a[j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return(0);
}