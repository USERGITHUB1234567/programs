#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.size()==1) {
        cout << 1;
        return 0;
    }
    int kq=0,d=0;
    for(int i=1; i<s.size(); i++) {
        if(s[i]!=s[i-1]) kq++;
    }
    for(int i=1; i<s.size(); i++) {
        if(s[i]=='1' and s[i-1]=='0') {
            kq--;
            break;
        }
    }
    cout << kq+1;
    return 0;
}
