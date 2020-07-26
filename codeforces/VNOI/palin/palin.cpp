#include <bits/stdc++.h>

using namespace std;

#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define REV(i, r, l) for (int i = r; i >= l; i--)
#define SET(x, val) memset(x, val, sizeof(x))
#define vi vector < int >
#define ii pair < int, int >
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pp pop_back

const int inf = 1e9 + 7;
const int esf = 1e-9;
const int N = 1e4 + 7;

int query;

string mirror(string s) {
    string left = "", mid = "", right = "";
    int n = s.length();
    REP(i, n / 2) left += s[i];
    if (n % 2) mid = s[n / 2];
    REP(i, left.length()) right = left[i] + right;
    return (left + mid + right);
}

int cmp(string a, string b) {   //  0 == equal, 1 == greater, -1 == less
    if (a.length() < b.length()) return (-1);
    if (a.length() > b.length()) return (1);
    REP(i, a.length()) {
        int aa = int(a[i]) - '0';
        int bb = int(b[i]) - '0';
        if (aa < bb) return (-1);
        if (aa > bb) return (1);
    }
    return (0);
}

string add(string s, string target) {
    string res = "";
    int n = s.length();
    REP(i, n / 2) res += s[i];
    if (n % 2 != 0) res += s[n / 2];    
    //cout << "res: " << res << endl;
    string tmp = "1";
    int carry = 0;
    while (tmp.length() != res.length()) tmp = '0' + tmp;
    REV(i, res.length() - 1, 0) {
        int a = int(res[i]) - '0' + carry + tmp[i] - '0';
        carry = a / 10;
        res[i] = char(a % 10 + '0');
    }
    //cout << "res:: " << res << endl;
    string right = "";
    if (n % 2 == 0) REP(i, res.length()) right += res[res.length() - i - 1];
    else REP(i, res.length() - 1) right = res[i] + right;
    return (res + right);
}

int main() {
    fileInput("palin");
    fast;
    cin >> query;
    REP(qq, query) {
        string s, mirr_s;
        cin >> s;
        mirr_s = mirror(s);
        //cout << "mirr_s: " << mirr_s << endl;
        mirr_s = add(mirr_s, s);
        cout << mirr_s << endl; 
    }
    return (0);
}