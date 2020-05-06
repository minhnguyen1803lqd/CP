#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e2 + 10;
const int oo = 1e9 + 7;

#define setup freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define StartCountTime clock_t t;   t = clock();
#define StopCountTime t = clock() - t;    cerr << ((float)t) / CLOCKS_PER_SEC << endl;
#define ii pair < int, int >
#define fi first
#define se second

int a[N][N];
int location[N];
vector < ii > square[N];
vector < ii > query;

void Prepare() {
    int cnt = 0;
    for (int i = 1; i <= 3; i++) {
        for (int k = 1; k <= 3; k++) {
            for (int j = 1; j <= 3; j++) {
                for (int h = 1; h <= 3; h++) {
                    int th = (3 * (i - 1) + j);
                    location[++cnt] = th;
                    int x = ((i - 1) * 3 + k);
                    int y = ((j - 1) * 3 + h);
                    square[th].push_back(ii(x, y));
                }
            }
        }
    }
    return;
}

bool Try(int x, int y, int val) {
    for (int i = 1; i <= 9; i++) {
        if (a[x][i] == val) {
            return (false);
        }
    }
    for (int i = 1; i <= 9; i++) {
        if (a[i][y] == val) {
            return (false);
        }
    }
    int th = (9 * (x - 1) + y);
    vector < ii > tmp = square[location[th]];

    for (int i = 0; i < tmp.size(); i++) {
        ii u = tmp[i];
        if (a[u.fi][u.se] == val) {
            return (false);
        }
    }
    return (true);
}

void Recur(int id) {
    if (id == query.size()) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    } else {
        ii u = query[id];
        for (int i = 1; i <= 9; i++) {
            bool res = Try(u.fi, u.se, i);
            if (res) {
                a[u.fi][u.se] = i;
                Recur(id + 1);
                a[u.fi][u.se] = 0;
            }
        }
    }
}

int main() {
    setup;
    StartCountTime;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                query.push_back(ii(i, j));
            }
        }
    }

    Prepare();
    Recur(0);

    StopCountTime;
}
