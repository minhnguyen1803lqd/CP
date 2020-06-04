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
    fo << "1\n";
    int n1 = rand() % 10 + 1;
    int n2 = rand() % 10 + 1;
    fo << n1 << " " << n2 << " ";
    int s = rand() % 2000 + 1;
    int c = rand() % 100 + 1;
    fo << s << " " << c << endl;
    for (int i = 1; i <= n1; i++) {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        fo << x << " " << y << endl;
    }
    for (int i = 1; i <= n2; i++) {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        fo << x << " " << y << endl;
    }
    fo.close();
}

void compareOutput() {
    system(("./" + problemName).c_str());
    system("./bruce");
    if (!system(("cmp " + problemName + ".out " + problemName + ".ans").c_str())) {
        correctQuery++;
    } else {
        exit(0);
    }
}
