#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    freopen("rsp.inp", "r", stdin);
    freopen("rsp.out", "w", stdout);
    int n,kq;
    cin >> n;
    kq=n;
    string s;
    cin >> s;
    for(int i=0; i<n-1; i++) {
        if(s[i]==s[i+1]) {
            kq--;
            i++;
        }
    }
    cout << kq;
}
