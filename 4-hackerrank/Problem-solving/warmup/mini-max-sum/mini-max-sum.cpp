/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e5 + 10;
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

long long minS, maxS, a[6];

int main() {
    FileOpen;
    for (int i = 1; i <= 5; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 6);
    for (int i = 1; i <= 4; i++) minS += a[i];
    for (int i = 2; i <= 5; i++) maxS += a[i];
    cout << minS << " " << maxS << endl;
}
