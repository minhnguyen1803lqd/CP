#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

vector < int > a;
int r0[] = {1, 2, 3, 4};
int r90[] = {3, 1, 4, 2};
int r180[] = {4, 3, 2, 1};
int r270[] = {2, 4, 1, 3};

main() {
    fileInput("quaybang");
    a.resize(4);
    for (int i = 0; i < 4; i++) cin >> a[i];
}
