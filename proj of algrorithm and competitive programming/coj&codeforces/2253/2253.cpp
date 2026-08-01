#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long t=0,ta=0;
    bool c=0,c2=0;
    s+='!';
    for(long long i=0; i<s.size(); i++) {
        if(s[i]=='1' and s[i+1]=='0') c=1;
        if(s[i]=='0' and s[i+1]=='1') c2=1;
        if(c2==1) {
            t+=ta;
            ta=0;
            c=0;
            c2=0;
        }
        if(c==1) ta++;
    }
    cout << t;
}
