#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e200;
const int oo = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int n, m, turn, currentTurn;
string player[3] = {"Bot ", "You "};

int GetCurrentStage(int n, int m) {
    if (n % 2 != 0 and m % 2 != 0) return (0);
    return (1);
}

void PushInP(int &n, int &m) {
    for (int i = 1; i <= n / 2 + 1; i++) {
        if (i % 2 != 0 and (n - i) % 2 != 0) {
            m = n - i;
            n = i;
            return;
        }
    }
    for (int i = 1; i <= m / 2 + 1; i++) {
        if (i % 2 != 0 and (m - i) % 2 != 0) {
            n = m - i;
            m = i;
            return;
        }
    }
    m = n / 2;
    n = n - m;
    return;
}

void ExtendGame(int &n, int &m) {
    int a;
    if (n < m) a = m;
    else a = n;
    n = 1;
    m = a - 1;
    return;
}

bool EndGame(int n, int m) {
    if (n == 1 and m == 1) return (true);
    return (false);
}

void Computer(int &currentTurn) {
    currentTurn = 0;
    int CurrentStage = GetCurrentStage(n, m);
    if (CurrentStage) {
        PushInP(n, m);
    } else {
        ExtendGame(n, m);
    }
    cout << "====== Computer move: " << n << " " << m << endl;
}

void Human(int &currentTurn) {
    currentTurn = 1;
    cout << "New N, M: ";
    cin >> n >> m;
    cout << "====== Your move: " << n << " " << m << endl;
    return;
}

void Expect() {
    int stage = GetCurrentStage(n, m);
    if (!stage) cout << player[currentTurn] << "will win =))\n";
    return;
}

int main() {
    srand(time(NULL));
    n = rand() % 20 + 5;
    m = rand() % 20 + 5;
    cout << "Go first or second? (1 == go first, 0 == go second)\n";
    cout << ">> ";
    cin >> turn;
    cout << "------- GAME START ------\n\n";
    cout << "Begin N and M: " << n << " " << m << endl;
    //Expect();
    if (turn) Human(currentTurn);
    while (!EndGame(n, m)) {
        Computer(currentTurn);
        if (EndGame(n, m)) break;
        Human(currentTurn);
    }
    cout << "Loser: " << player[abs(currentTurn - 1)] << endl;
}
