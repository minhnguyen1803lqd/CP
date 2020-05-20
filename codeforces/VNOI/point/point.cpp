#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;

struct point {
    int x, y;
};

int n, query;

int Q(int x, int y) {
    for (int i = 1; i <= n; i++) {
        
    }
}

int main() {
    fileInput("point");
    fast;
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> point[i].x >> point[i].y;
        }
    }

    return (0);
}