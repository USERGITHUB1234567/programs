#include <bits/stdc++.h>
using namespace std;
int to(int n)
{
    int t=0;
    while(n>0) {
        t+=n%10;
        n/=10;
    }
    return t;
}
int main()
{
    string s;
    cin >> s;
    string sd;
    sd+=s[0];
    string sc;
    sc+=s[4];
    string t=s.substr(1,3);
    int tsd=stoll(sd)*2,tsc=stoll(sc)*2;
    if(tsd>=10) {
        int k1=to(tsd);
        cout << k1;
    }
    else cout << tsd;
    sort(t.begin(),t.end());
    cout << t;
    if(tsc>=10) {
        int k2=to(tsc);
        cout << k2;
    }
    else cout << tsc;
}
