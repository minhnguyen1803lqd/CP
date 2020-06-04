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
const int N = 1e4 + 7;

string s;
int card[N][N];
int cardType[4] = {int('P'), int('K'), int('H'), int('T')};

void extrac(string s) {
    int n = s.length();
    for (int i = 0; i < n; i += 3) {
        int type = int(s[i]);
        int num = (int(s[i + 1]) - int('0')) * 10 + (int(s[i + 2]) - int('0'));
        card[type][num]++;
    }
}

bool duplicate() {
    for (int i = 0; i < 4; i++) {
        int type = cardType[i];
        for (int j = 1; j <= 13; j++) {
            if (card[type][j] == 2) return (true);
        }
    }
    return (false);
}

int main() {
        fileInput("poker");
    fast;
    cin >> s;
    extrac(s);
    if (duplicate()) cout << -1 << endl;
    else {
        for (int i = 0; i < 4; i++) {
            int cnt = 0;
            int type = cardType[i];
            for (int j = 1; j <= 13; j++) {
                if (card[type][j] == 1) cnt++;
            }
            cout << 13 - cnt << " ";
        }
    }
    return (0);
}