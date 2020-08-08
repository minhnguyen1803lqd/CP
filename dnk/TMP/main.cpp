#include <bits/stdc++.h>

using namespace std;

int ok[100];

int main() {
    srand(time(NULL));
    for (int i = 1; i <= 16; ++i) {
        int u;
        do {
            u = rand() % 16 + 1;
        } while (ok[u]);
        ok[u] = 1;
        cout << u << endl;
    }
}
