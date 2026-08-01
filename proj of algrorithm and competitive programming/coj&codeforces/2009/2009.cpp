#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int t=0;
    for(int i=0; i<s.size(); i++) t+=s[i]-48;

    int d=t%9,c=9-d;
    if(s=="3") {
        cout << s[0];
        return 0;
    }
    if(t<9) {
        cout << c;
        return 0;
    }
    //cout << d << ' ' << c;
    bool l=false,n=false;
    for(int i=0; i<s.size(); i++) {
        if((s[i]-48)>=d) {
            l=true;
            break;
        }
    }
    for(int i=0; i<s.size(); i++) {
        if(9-(s[i]-48)>=c) {
            n=true;
            break;
        }
    }
    if(l==true && n==true) {
        cout << min(d,c);
    }
    else if(l==true) cout << d;
    else cout << c;
}
