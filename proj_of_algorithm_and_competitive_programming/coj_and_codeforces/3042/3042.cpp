#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int re=0;
    for(int i=0; i<s.size(); i++) {
        while(s[i+1]==s[i] and i<n-1) {
            re++;
            s.erase(i+1,1);
        }
    }
    cout << re;
}
