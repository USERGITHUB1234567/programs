#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,d=0;
    cin >> n;
    while(n>0) {
        string s=to_string(n);
        long long t=0;
        for(int i=0; i<s.size(); i++) {
            long long a=s[i]-48;
            t=max(t,a);
        }
        n-=t;
        d++;
    }
    cout << d;
}
