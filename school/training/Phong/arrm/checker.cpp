#include <bits/stdc++.h>

using namespace std;

int _query, correctQuery = 0;
string problemName;
int n, query;
int u, v, val;

void generateInput();
void compareOutput();

int main() {
    srand(time(NULL));
    cout << "Problem's name: ";
    cin >> problemName;
    cout << "Queries: ";
    cin >> _query;
    for (int qq = 1; qq <= _query; qq++) {
        generateInput();
        compareOutput();
    }
    cout << "Correct: " << correctQuery << "/" << _query << endl;
}

void generateInput() {
    ofstream fo ((problemName + ".inp").c_str());
    int n = rand() % 100 + 1;
    int query = rand() % 30 + 1;
    fo << n << " " << query << endl;
    for (int qq = 1; qq <= query; qq++) {
        u = rand() % n + 1;
        v = rand() % n + 1;
        val = rand() % 500 + 1;
        fo << u << " " << v << " " << val << endl;
    }
    fo.close();
}

void compareOutput() {
    system(("./" + problemName).c_str());
    system("./bruce");
    if (!system(("cmp " + problemName + ".out " + problemName + ".ans").c_str())) {
        correctQuery++;
    }
}
