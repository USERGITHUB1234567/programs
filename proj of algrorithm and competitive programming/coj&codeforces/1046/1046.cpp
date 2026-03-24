#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b;
    cin >> a >> b;
    long long t1,t2;
    string s1=to_string(a),s2=to_string(b);
    for(long long i=0; i<s1.size(); i++) {
        if(s1[i]=='5') s1[i]='6';
    }
    for(long long i=0; i<s2.size(); i++) {
        if(s2[i]=='5') s2[i]='6';
    }
    a=stoll(s1);
    b=stoll(s2);
    t1=a+b;
    for(long long i=0; i<s1.size(); i++) {
        if(s1[i]=='6') s1[i]='5';
    }
    for(long long i=0; i<s2.size(); i++) {
        if(s2[i]=='6') s2[i]='5';
    }
    a=stoll(s1);
    b=stoll(s2);
    t2=a+b;
    cout << min(t1,t2) << " " << max(t1,t2);
}
