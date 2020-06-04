/*

 */
#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e200;
const int inf = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int Sum(int a, int b) {
    return (a + b);
}

main() {
    FileOpen;
    cin >> a >> b;
    cout << Sum(a, b) << endl;
}
