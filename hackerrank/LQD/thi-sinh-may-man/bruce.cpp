#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long a[100050];

int main() {
    freopen ("thi-sinh-may-man.inp", "r", stdin);
    freopen ("thi-sinh-may-man.ans", "w", stdout);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int counter = 0;
        //cout << "a[i]: " << a[i] << " = {";
        for (int j = i; j <= n; j++) {
            if (i != j && abs(a[i] + a[j]) == k) {
                res++;
                //cout << a[j] << " ";
                counter++;
            }
        }
        //cout << "}" << endl;
        //cout << "counter: " << counter << endl;
    }
    cout << res << endl;
    return 0;
}