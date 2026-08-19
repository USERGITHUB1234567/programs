#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long t=0;
    long long a=1,d=0;
    while(a<n) {
        a*=10;
        d++;
    }
    if(a>n) {
        a/=10;
        d--;
    }
    long long e=9,i=1;
    while(d--) {
        t+=e*i;
        e*=10;
        i++;
    }
    string s=to_string(n);
    string c="";
    while(c.size()<s.size()-1) c+='9';
    long long f=stoll(c);
    n-=f;
    long long b=s.size();
    t+=n*b;
    cout << t;
    return 0;
}
