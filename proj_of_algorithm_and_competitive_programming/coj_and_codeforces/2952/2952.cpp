#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i=1; i<s.size(); i++) {
        if(s[i]=='0' and s[i-1]=='0') {
            s.erase(i,1);
            i--;
        }
    }
    s.erase(s.size()-1,1);
    cout << s;
    return 0;
}
