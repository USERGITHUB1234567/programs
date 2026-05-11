#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n,d=0;
    cin >> n;
    string s,t;
    cin >> s >> t;
    for(int i=0; i<n; i++) {
        int a=s[i]-48,b=t[i]-48;
        int k=abs(a-b);
        d+=min(k,10-k);
    }
    cout << d;
}
