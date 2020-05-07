#include <bits/stdc++.h>

using namespace std;

string Task1 = "c";
string Task2 = "bruce";

int query;

void CreateQuery() {
    ofstream fo ("task.inp");
    fo.close();
}
void RunTasks() {
    system((Task1 + ".exe").c_str());
    system((Task2 + ".exe").c_str());
}
int CheckResult() {
    int res = system("FC task.out task.ans");
    return (res);
}

int main() {
    srand(time(NULL));
    cout << "Input amount of test: ";
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        cout << "----Test number " << qq << " -------" << endl;
        CreateQuery();
        RunTasks();
        if (CheckResult() == 0) {
            cout << "Pass test " << qq << endl;
            cout << "--------------------------" << endl;
        } else if (CheckResult() == 1) {
            cout << "Detected differences on test " << qq << "." << endl;
            cout << "Checker shut down!\n";
            exit(0);
        } else if (CheckResult() == -1) {
            cout << "Syntax problem!" << endl;
            exit(0);
        } else if (CheckResult() == 2) {
            cout << "One of the two files cannot be found!" << endl;
            exit(0);
        }
    }
    cout << "Checking complete!\n";
    return true;
}
