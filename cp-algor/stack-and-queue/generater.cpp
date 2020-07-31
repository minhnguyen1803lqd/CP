#include <bits/stdc++.h>

using namespace std;

int n, query, type;
vector < int > a;

int main() {
    srand(time(NULL));
    freopen ("stack-and-queue.inp", "w", stdout);
    
    /*  manual:
    * 0 x: add x into the array
    * 1: find the minimum number in the array
    * 2: delete the latest element in the array
    */
    query = 3 + rand() % 10 + 1;
    cout << query << endl;
    while (query--) {
        type = rand() % 3;
        if (type == 0) cout << "0 " << rand() % 20 + 1 << endl;
        else cout << type << endl;
    }

    return (0);
}