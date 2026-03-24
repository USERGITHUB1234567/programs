#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int a[4];
        for(int i=0; i<4; i++) cin >> a[i];
        bool sm=false,tr=false;
        for(int i=0; i<4; i++) {
            for(int j=i+1; j<4; j++) {
                for(int k=j+1; k<4; k++) {
                    int ma=max({a[i],a[j],a[k]}),mi=min({a[i],a[j],a[k]});
                    if(mi+(a[i]+a[j]+a[k])-ma-mi>ma) {
                        tr=true;
                    }
                    else if(mi+(a[i]+a[j]+a[k])-ma-mi==ma) sm=true;
                }
            }
        }
        if(tr==true) cout << "TRIANGLE\n";
        else if(sm==true) cout << "SEGMENT\n";
        else cout << "IMPOSSIBLE\n";
}
