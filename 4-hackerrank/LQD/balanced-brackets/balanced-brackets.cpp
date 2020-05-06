#include <bits/stdc++.h>

#define fi first
#define se second
#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fast ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

const int N = 1e4 + 10;
const int oo = 1e9 + 7;

int n;
string s;

bool Open(char x) {
	if (x == '(' || x == '{' || x == '[') {
		return true;
	} else {
		return false;
	}
}

bool Pairable(char x, char y) {
	if (x == '(' && y == ')' || x == '{' && y == '}' || x == '[' && y == ']') {
		return true;
	} else {
		return false;
	}
}

bool Check(string s) {
	stack < char > st;
	for (int i = 0 ; i < s.length(); i++) {
		if (Open(s[i])) {
			st.push(s[i]);
		} else {
			if (st.size() != 0) {
				if (Pairable(st.top(), s[i])) {
					st.pop();
				} else {
					return false;
				}
			} else {
				return false;
			}		
		}
	}
	if (st.size() != 0) {
		return false;
	}
	return true;
}

string Translate(bool x) {
	if (x) return ("YES");
	return ("NO");
}

int main()
{
	fast;
	freopen ("balanced-brackets.inp", "r", stdin);
	freopen ("balanced-brackets.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		cout << Translate(Check(s)) << endl;
	}
}
