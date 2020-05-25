#include <bits/stdc++.h>

using namespace std;

int query, correctQuery = 0;
string problemName;

long long n, a, b;

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
    
    n = rand() % int(1e9) + 1;
    do {
        a = rand() % int(1e9) + 1;
        b = rand() % int(1e9) + 1;
    } while (a >= b);
    fo << n << " " << a << " " << b << endl;

    fo.close();
}

void compareOutput() {
    system(("./" + problemName).c_str());
    system("./bruce");
    long long tmp1, tmp2;
    ifstream f1 ("onum.ans");
    ifstream f2 ("onum.out");
    f1 >> tmp1;
    f2 >> tmp2;
    if (tmp1 == tmp2) {
        cout << "correct\n";
        correctQuery++;
    } else {
        cout << "WA\n";
        exit(0);
    }
    f1.close();
    f2.close();
    // if (!system(("cmp " + problemName + ".out " + problemName + ".ans").c_str())) {
    //     correctQuery++;
    // }
}
