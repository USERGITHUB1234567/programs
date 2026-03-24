#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.size()%2==0) {
        for(int i=0; i<s.size(); i+=2) {
            if(i==0 && s[i]=='1') continue;
            if(s[i]!='0') {
                cout << "First";
                return 0;
            }
        }
        cout << "Second";
        return 0;
    }
    else {
        /*if(s[0]!='9') {
            cout << "First";
            return 0;
        }*/

        for(int i=1; i<s.size(); i+=2) {
            if(s[i]!='0'&& s[i-1]=='9') {
                cout << "Second";
                return 0;
            }
            if(s[i]!='0'&& s[i-1]=='9') {
                cout << "First";
                return 0;
            }
        }
        cout << "First";
        return 0;
    }
}
