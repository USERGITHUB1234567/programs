#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    long double a1,b1,a2,b2;
    cin >> a1 >> b1 >> a2 >> b2;
    if(min(a1,b1)/min(a2,b2)==max(a1,b1)/max(a2,b2)) cout << "YES";
    else cout << "NO";
}
