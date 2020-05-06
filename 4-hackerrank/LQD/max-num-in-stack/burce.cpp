#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7;

int query;
stack < int > st;

int FindMax(stack < int > ST) {
    int res = -oo;
    while (ST.empty() == false) {
        res = max(res, ST.top());
        ST.pop();
    }
    return res;
}

int main() {

    freopen ("max-num-in-stack.inp", "r", stdin);
    freopen ("burce.out", "w", stdout);

    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            st.push(x);
        } else if (type == 2) {
            if (st.empty() == false) {
                st.pop();
            } else {
                exit(0);
            }
        } else {
            int tmp = FindMax(st);
            cout << tmp << endl;
        }
    }
}