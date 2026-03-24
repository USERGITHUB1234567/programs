#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s;
int cut(string s)
{
    int i=s.size()-1;
    bool ck=false;
    while(s[i]==s[s.size()-i-1]) {
        i--;
        ck=true;
    }
    i++;
    if(ck) return i;
    else return -1;
}
int main()
{
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        int j=cut(s.substr(0,))
    }
}
