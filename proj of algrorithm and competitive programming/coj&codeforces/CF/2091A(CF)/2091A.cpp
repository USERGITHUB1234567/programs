#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int d[10];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    d[0]=3;
    d[1]=1;
    d[2]=2;
    d[3]=1;
    d[4]=0;
    d[5]=1;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n],g[10];
        int kq=0;
        memset(g,0,sizeof(g));
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) {
            //cin >> a[i];
            g[a[i]]++;
            bool ck=true;
            for(int i=0; i<=5; i++) {
                if(g[i]<d[i]) {
                    ck=false;
                    break;
                }
            }
            if(ck) {
                kq=i+1;
                break;
            }
        }
        cout << kq << "\n";
    }
}
