#include <bits/stdc++.h>

using namespace std;

long long ghepmin(long a, long b)
{
    if (a!=0 && b!=0)
        return min( ghepmin(a/10,b)*10+a%10 , ghepmin(a,b/10)*10+b%10 );
    else return (max(a,b));
}

long long ghepmax(long a, long b)
{
    if (a!=0 && b!=0)
        return max( ghepmax(a/10,b)*10+a%10 , ghepmax(a,b/10)*10+b%10 );
    else return (max(a,b));
}

int main()
{
    freopen ("MERGENUM.inp", "r", stdin);
    freopen ("MERGENUM.ans", "w", stdout);
    long a,b;
    cin >> a >> b;
    cout << ghepmin(a,b)<<endl;
    cout << ghepmax(a,b);
    return 0;
}