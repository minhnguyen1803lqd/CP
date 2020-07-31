#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define ll long long
#define ii pair < int, int >
#define fi first
#define se second

const ll inf = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll N = 0;

int query;
vector < int > a;
stack < ii > st;
queue < ii > q;
deque < ii > dq;

main() {
    fileInput("stack-and-queue");
    cin >> query;
    while (query--) {
        int key = 0;
        cin >> key;
        if (key == 0) {
            int val = 0;
            cin >> val;
            int new_min = st.empty() ? val : min(val, st.top().se);
            cout << "add new element: " << val << endl;
            st.push(make_pair(val, new_min));
        } else if (key == 1) {
            cout << "minimun element: " << st.top().se << endl;
        } else if (key == 2) {
            cout << "remove element: " << st.top().fi << endl;
            st.pop();
        }
    }
}