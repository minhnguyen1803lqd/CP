#include<bits/stdc++.h>

using namespace std;

int n;

int Sol(int n) {
    if (n < 10) return (n);
    int tmp = n;
    int res = 0;
    while (tmp != 0) {
        res += (tmp % 10);
        tmp /= 10;
    }
    if (res > 9) return (Sol(res));
    return (res);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << Sol(n);
    return 0;
}
