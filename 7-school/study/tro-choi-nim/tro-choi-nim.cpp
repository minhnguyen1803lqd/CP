#include <bits/stdc++.h>

using namespace std;

const string task = "task";
const int N = 1e200;
const int oo = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int x1, x2, x3, turn, currentTurn;
string player[] = {"bot ", "you "};

int GetStage(int x1, int x2, int x3) {
    if ((x1 ^ x2 ^ x3) == 0) return (0);
    return (1);
}

bool InputError(int x1, int x2, int x3, int inp1, int inp2, int inp3) {
    int diff = 0;
    if (x1 == inp1) diff++;
    if (x2 == inp2) diff++;
    if (x3 == inp3) diff++;
    if (diff != 2) return (1);
    if (x1 == inp1 and x2 == inp2 and x3 == inp3) return (1);
    if (x1 < inp1 or x2 < inp2 or x3 < inp3) return (1);
    if (inp1 < 0 or inp2 < 0 or inp3 < 0) return (1);
    if (inp1 > x1 or inp2 > x2 or inp3 > x3) return (1);
    return (0);
}

bool PushInP() {
    int c = 0, n = 0;
    for (int k = 1; k <= x1; k++) if (((x1 - k) ^ x2 ^ x3) == 0) c = 1, n = k;
    for (int k = 1; k <= x2; k++) if ((x1 ^ (x2 - k) ^ x3) == 0) c = 2, n = k;
    for (int k = 1; k <= x3; k++) if ((x1 ^ x2 ^ (x3 - k)) == 0) c = 3, n = k;
    if (c == 0) return (0);
    if (c == 1) x1 -= n;
    if (c == 2) x2 -= n;
    if (c == 3) x3 -= n;
    return (1);
}

void Extend() {
    if (x1 != 0) {
        x1 -= 1;
        return;
    }
    if (x2 != 0) {
        x2 -= 1;
        return;
    }
    if (x3 != 0) {
        x3 -= 1;
        return;
    }
}

void Computer() {
    currentTurn = 0;
    int currentStage = GetStage(x1, x2, x3);
    if (currentStage) {
        bool tmp = PushInP();
        if (!tmp) {
            cout << "You win!\n";
            exit(0);
        }
    }
    else Extend();
    cout << "bot's move: x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << endl;
}
void Human() {
    currentTurn = 1;
    cout << "x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << endl;
    int tmp1, tmp2, tmp3;
    do {
        cout << "new x1, x2, x3: ";
        cin >> tmp1 >> tmp2 >> tmp3;
    } while (InputError(x1, x2, x3, tmp1, tmp2, tmp3));
    x1 = tmp1;
    x2 = tmp2;
    x3 = tmp3;
    cout << "your move : x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << endl;
    return;
}

bool Lose() {
    return (x1 == 0 and x2 == 0 and x3 == 0);
}

int main() {
    //FileOpen;
    srand(time(NULL));
    cout << "go first or second? (1, 0)";
    cout << ">> ";
    cin >> turn;
    x1 = rand() % 10 + 1;
    x2 = rand() % 10 + 1;
    x3 = rand() % 10 + 1;
    x1 = 3;
    x2 = x3 = 6;
    cout << "BEGIN     : x1 = " << x1 << ", x2 = " << x2 << ", x3 = " << x3 << endl;
    if (turn) Human();
    while (true) {
        if (Lose()) {
            cout << player[abs(currentTurn - 1)] << "lose!\n";
            cout << player[currentTurn] << "win!\n";
            return (0);
        }
        Computer();
        if (Lose()) {
            cout << player[abs(currentTurn - 1)] << "lose!\n";
            cout << player[currentTurn] << "win!\n";
            return (0);
        }
        Human();
    }


}
