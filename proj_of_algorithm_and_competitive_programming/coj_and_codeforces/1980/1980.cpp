#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long borco(long long n)
{
    string s=to_string(n);
    long long t=s.size(),kq=(t-1)*9;
    kq++;
    bool ck=false;
    string c="";
    for(int i=0; i<s.size(); i++) {
        c+=s[0];
    }
    long long q=stoll(c);
    if(s.size()==1 or n>=q) ck=true;
    string s1="";
    s1+=s[0];
    long long b=stoll(s1);
    if(ck) kq+=b;
    else kq+=b-1;
    return kq;
}
int main()
{
    long long l,r;
    cin >> l >> r;
    cout << borco(r)-borco(l-1);
    //cout << borco(41);
    return 0;
}
