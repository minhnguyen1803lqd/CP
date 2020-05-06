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
    string digit[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    int lenOfA0 = rand() % 10 + 1;
    string a = "";
    for (int i = 0; i < lenOfA0; i++) {
        int tmp = rand() % 10;
        a += digit[tmp];
    }
    fo << a << endl;
    int res = rand() % 2;
    if (res) {
        int n = rand() % 25 + 1;
        fo << n << " ";
        n = (int)pow(2, n);
        int m = rand() % n + 1;
        fo << m << endl;
    } else {
        int n = rand() % 25 + 1;
        fo << n << " ";
        n = (int)pow(2, n);
        int m = rand() % n + rand() % 5;
        fo << m << endl;
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
