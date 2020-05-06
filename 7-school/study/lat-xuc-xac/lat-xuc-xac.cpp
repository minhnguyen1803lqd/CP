#include <bits/stdc++.h>

using namespace std;

const string task = "task";
//const int N = 1e200;
const int oo = 1e9 + 7;

#define FileOpen freopen ((task + ".inp").c_str(), "r", stdin);	freopen ((task + ".out").c_str(), "w", stdout);

int N;
int FaceUp;
int HumanPoint = 0, ComputerPoint = 0;

int human(const int N, int HumanPoint) {
    int FaceDown = 7 - FaceUp;
    int HumanPick = 0;
    while (true) {
        cout << "you can pick: ";
        for (int i = 1; i <= 6; i++) {
            if (i != FaceDown and i != FaceUp) cout << i << " ";
        }
        cout << endl;
        cout << "your choice: ";
        cin >> HumanPick;
        if (HumanPick != FaceDown and HumanPick != FaceUp) break;
    }
    cout << "-- Human picked: " << HumanPick << endl;
    FaceUp = HumanPick;
    return (HumanPoint + HumanPick);
}

int computer(const int N, int ComputerPoint) {
    int FaceDown = 7 - FaceUp;
    int ComputerPick = 0;
    do {
        ComputerPick = rand() % 6 + 1;
        if (ComputerPick != FaceUp and ComputerPick != FaceDown and ComputerPick + ComputerPoint == N) {
            FaceUp = ComputerPick;
            cout << "-- Computer picked: " << ComputerPick << endl;
            return (ComputerPoint + ComputerPick);
            break;
        }
    } while (ComputerPick == FaceDown or ComputerPick == FaceUp);
    cout << "-- Computer picked: " << ComputerPick << endl;
    FaceUp = ComputerPick;
    return (ComputerPoint + ComputerPick);
}

int main() {
    //FileOpen;
    srand(time(NULL));
    N = rand() % 30 + 1;
    FaceUp = rand() % 6 + 1;
    cout << "GAME START!!!\n\n";
    cout << "Limit: " << N << endl;
    do {
        cout << "--- HUMAN Turn\n";
        cout << "- FaceUp: " << FaceUp << endl;
        HumanPoint = human(N, HumanPoint);
        if (HumanPoint > N) {
            cout << "Computer win!\nHuman lose!";
            return (0);
        }
        cout << "--- COMPUTER Turn\n";
        cout << "- FaceUp: " << FaceUp << endl;
        ComputerPoint = computer(N, ComputerPoint);
        if (ComputerPoint > N) {
            cout << "Human win!\nComputer lose!";
            return (0);
        }
        cout << "Current point: \n";
        cout << "-- Human: " << HumanPoint << endl;
        cout << "-- Computer: " << ComputerPoint << endl;
    } while (HumanPoint <= N and ComputerPoint <= N);

}
