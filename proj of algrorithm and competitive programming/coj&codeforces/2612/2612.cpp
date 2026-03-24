#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a=0,b=0;
    cin >> n;
    string s;
    cin >> s;
    for(long long i=0; i<s.size(); i++) {
        if(s[i]=='A') a++;
        else b++;
    }
    if(a>b) cout << ">";
    if(a<b) cout << "<";
    if(a==b) cout << "=";
}
