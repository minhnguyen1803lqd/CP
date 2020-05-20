#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 1e4 + 7;

struct point {
    int x, y;
};

int n;
point redPnt[N], bluePnt[N];

bool cmp(point a, point b) {
    return (a.x * b.y < b.x * a.y);
}

int main() {
    fileInput("ballgmvn");
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> redPnt[i].x >> redPnt[i].y;
    }
    for (int i = 1; i <= n; i++) {
        cin >> bluePnt[i].x >> bluePnt[i].y;
    }

    for (int i = 1; i <= n; i++) {
        cout << redPnt[i].x << " " << redPnt[i].y << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << bluePnt[i].x << " " << bluePnt[i].y << endl;
    }

    cout << endl;

    for (int i = 2; i <= n; i++) {
        redPnt[i].x -= redPnt[1].x;
        redPnt[i].y -= redPnt[1].y;
    }
    redPnt[1].x = 0;
    redPnt[1].y = 0;
    for (int i = 2; i <= n; i++) {
        bluePnt[i].x -= bluePnt[1].x;
        bluePnt[i].y -= bluePnt[1].y;
    }
    bluePnt[1].x = 0;
    bluePnt[1].y = 0;

    for (int i = 1; i <= n; i++) {
        cout << redPnt[i].x << " " << redPnt[i].y << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << bluePnt[i].x << " " << bluePnt[i].y << endl;
    }

    sort(redPnt + 1, redPnt + 1 + n, cmp);
    sort(bluePnt + 1, bluePnt + 1 + n, cmp);

    cout << endl;
    
    for (int i = 1; i <= n; i++) {
        cout << redPnt[i].x << " " << redPnt[i].y << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << bluePnt[i].x << " " << bluePnt[i].y << endl;
    }

    return (0);
}