#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("bit1.inp", "r", stdin);
    //freopen("bit1.out", "w", stdout);
    unsigned long long n;
    cin >> n;
    string s="";
    while(n>0) {
        if(n%2==0) s='0'+s;
        else s='1'+s;
        n/=2;
    }
    cout << s;
}
