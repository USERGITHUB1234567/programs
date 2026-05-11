#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        //int du=0,di=0;
        int d=0,l=-1,r=-1,n=s.size();
        char c='*';
        for (int i=0; i<=n-3; i++){
            bool u=false, ii=false;
            for (int j=i; j<i+3; j++){
                if(s[j]=='U') u=true;
                if(s[j]=='I') ii=true;
            }
            if(u && ii){
                l=i+1;
                r=i+3;
                break;
            }
        }
        if(l==-1 || r==-1) cout << "NO\n";
        else cout << "YES "  << l << " " << r << "\n";
    }
}
/*
4
UUUIIIUIIUI
UU
IUUIIUUI
IU
*/
