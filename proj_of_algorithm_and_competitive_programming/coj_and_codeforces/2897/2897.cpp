#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    string s;
    cin >> s;
    int kq=1, d=1;
    for(int i=1; i<s.size(); i++) {
        if(s[i]==s[i-1]) d++;
        else {
            kq=max(kq,d);
            d=1;
        }
    }
    kq=max(kq,d);
    cout << kq;
    return 0;
}
