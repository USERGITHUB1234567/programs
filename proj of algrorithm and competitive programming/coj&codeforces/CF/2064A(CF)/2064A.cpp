#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,kq=0;
        cin >> n;
        string s,t="";
        cin >> s;
        bool ck=false;
        if(s[0]==1) ck=true;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='1') ck=true;
            else if(s[i]=='0' and ck) {
                int j=i;
                while(s[j]=='0' and j<n) j++;
                j--;
                kq+=2;
                i=j;
                ck=false;
            }
        }
        if(ck) kq++;
        cout << kq << "\n";
    }
    return 0;
}
