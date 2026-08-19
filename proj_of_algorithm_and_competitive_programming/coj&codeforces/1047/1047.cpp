#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long a[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    long long a2[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    long long t=0;
    for(long long i=0; i<s.size(); i++) {
        if(a[s[i]-'a']==a[s[i-1]-'a']) t+=2;
        t+=a2[s[i]-'a'];
    }
    cout << t;
}
