#include <bits/stdc++.h>

using namespace std;

int query, correctQuery = 0;
string problemName;

void generateInput();
void compareOutput();

int main() {
    srand(time(NULL));
    cout << "Problem's name: ";
    cin >> problemName;
    cout << "Queries: ";
    cin >> query;
    for (int qq = 1; qq <= query; qq++) {
        generateInput();
        compareOutput();
    }
    cout << "Correct: " << correctQuery << "/" << query << endl;
}

void generateInput() {
    ofstream fo ((problemName + ".inp").c_str());
    fo.close();
}

void compareOutput() {
    system(("./" + problemName).c_str());
    system("./bruce");
    if (!system(("cmp " + problemName + ".out " + problemName + ".ans").c_str())) {
        correctQuery++;
    }
}
