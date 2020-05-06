#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e200;
const int oo = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);
#define vi vector < int >

vi DecToBin(int x) {
    vi res;
    int tmp = x;
    while (tmp != 0) {
        res.push_back(tmp % 2);
        tmp /= 2;
    }
    return (res);
}

void Print(vi x) {
    for (int i = x.size() - 1; i >= 0; i--) cout << x[i]; cout << endl;
    return;
}

int main() {
    //FileOpen;
    int a = 5;
    int b = 10;
    Print(DecToBin(a));
    Print(DecToBin(b));
    cout << (a ^ b) << endl;
}
