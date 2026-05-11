#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        map<int,int>mp;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        if(n==1) {
            cout << 1 << " " << 1 << "\n";
            continue;
        }
        /*while(mp[a[i]]==1 and i<n) {
            i++;
        }
        while(mp[a[j]]==1 and j>0) {
            j--;
        }
        if(j-i+1==n) cout << 0 << "\n";
        else cout << i+1 << " " << j+1 << "\n";*/
        int m=0,l=0,r=0,kq1,kq2;
        bool ck=false;
        for(auto x:mp) {
            if(x.second==1) {
                ck=true;
                break;
            }
        }
        if(!ck) {
            cout << 0 << "\n";
            continue;
        }
        for(r; r<n; r++) {
            if(mp[a[r]]>1) {
                l=r+1;
                //cout << l << " " << r << "\n";
            }
            if(r-l+1>m) {
                kq1=l;
                kq2=r;
                m=r-l+1;
            }
        }
        /*if(max(kq1,kq2)-min(kq1,kq2)+1==n) {
           cout << 0 << "\n";
           continue;
        }*/
        //if(max(kq1,kq2)-min(kq1,kq2)+1==n) cout << 0 << "\n";
        cout << min(kq1,kq2)+1 << " " << max(kq1,kq2)+1 << "\n";
    }
    return 0;
}
