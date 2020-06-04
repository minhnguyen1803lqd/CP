#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e3 + 7;

ll n;
vector < int > p;

void extract(int n, vector < int > &p) {
    while (n) {
        p.push_back(n % 3);
        n /= 3;
    }
    p.push_back(0);
    return;
}

void process(vector < int > p) {
    vector < int > left, right;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == 0) {
            continue;
        } else if (p[i] == 1) {
            right.push_back(int(pow(3, i)));
        } else if (p[i] == 2) {
            left.push_back(int(pow(3, i)));
            p[i + 1] += 1;
        }
    }
    cout << left.size() << " ";
    for (int i = 0; i < left.size(); i++) {
        cout << left[i] << " ";
    }
    cout << endl;
    cout << right.size() << " ";
    for (int i = 0; i < right.size(); i++) {
        cout << right[i] << " ";
    }
    cout << endl;
}

int main() {
    fileInput("can3");
    fast;
    
    cin >> n;

    extract(n, p);
    process(p);

    return (0);
}