#include <bits/stdc++.h>

#define vi vector < int >

using namespace std;

const int BASE = 10000;
const int N = 1e3 + 7;

vi a, b;

void fix(vi &a) {
    a.push_back(0);
    for (int i = 0; i < a.size() - 1; ++i) {
        a[i + 1] += a[i] / BASE;
        a[i] %= BASE;
        if (a[i] < 0) {
            a[i] += BASE;
            a[i + 1]--;
        }
    }
    while (a.size() >= 2 && a.back() == 0) a.pop_back();
}

vi to_vi(int x) {   //  x < BASE
    assert(x < BASE);
    return (vi(1, x));
}

vi operator* (const vi &a, const vi &b) {
    vi c(a.size() + b.size() + 1);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j <= b.size(); ++j) {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i + j] / BASE;
            c[i + j] %= BASE;
        }
    }
    return (fix(c), c);
}

vi operator+ (vi a, const vi &b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); ++i) {
        a[i] += b[i];
    }
    return (fix(a), a);
}

vi operator- (vi a, const vi &b) {
    for (int i = 0; i < b.size(); ++i) {
        a[i] -= b[i];
    }
    return (fix(a), a);
}

vi operator* (vi a, int x) {   //  x < BASE
    assert(x < BASE);
    for (int i = 0; i < a.size(); ++i) {
        a[i] *= x;
    }
    return (fix(a), a);
}

bool operator< (const vi &a, const vi &b) {
    if (a.size() != b.size()) {
        return (a.size() < b.size());
    }
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            return (a[i] < b[i]);
        }
    }
    return (false);
}

vi operator/ (vi a, int x) {    //  x < BASE
    assert(x < BASE);
    vi c = to_vi(0);
    for (int i = (int)a.size() - 1, r = 0; i >= 0; i--, r %= x) {
        r = r % BASE + a[i];
        c[i] = r / x;
    }
    return (fix(c), c);
}

int operator% (vi a, int x) {   //  x < BASE
    int r = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        r = (r * BASE + a[i]) % x;
    }
    return (r);
}

istream &operator>> (istream &cin, vi &a) {
    string s;
    cin >> s;
    a.clear();
    a.resize(s.size() / 4 + 1);
    for (int i = 0; i < s.size(); ++i) {
        int x = (s.size() - 1 - i) / 4; //  log10(BASE) = 4
        a[x] = a[x] * 10 + (s[i] - '0');
    }
    return (fix(a), cin);
}

ostream &operator<< (ostream &cout, vi &a) {
    printf("%d", a.back());
    for (int i = (int)a.size() - 2; i >= 0; i--) {
        printf("%04d", a[i]);
    }
    return (cout);
}

int main() {
    freopen ("latgach.inp", "r", stdin);
    freopen ("latgach.out", "w", stdout);
    
    vi fib[N];
    fib[1] = to_vi(1);
    fib[2] = to_vi(2);
    for (int i = 3; i <= 100; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int query;
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        int n;
        cin >> n;
        cout << fib[n] << endl;
    }

    return (0);
}