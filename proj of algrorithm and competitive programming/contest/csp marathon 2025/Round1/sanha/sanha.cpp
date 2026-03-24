#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005,inf=INT_MAX;
int n,q,a[maxn];
void soup()
{
    while(q--) {
        int l,r,kq=1;
        cin >> l >> r;
        vector<int>v;
        map<int,bool>mp;
        for(int i=l; i<=r; i++) {
            if(!mp[a[i]]) {
                v.push_back(a[i]);
                mp[a[i]]=true;
            }
        }
        sort(v.begin(),v.end());
        for(int i=1; i<v.size(); i++) {
            int ql=inf,qr=0;
            for(int j=l; j<=r; j++) {
                if(a[j]==v[i]) {
                    ql=min(ql,j);
                    qr=max(qr,j);
                }
            }
            int pre=-1;
            for(int j=ql; j<=qr; j++) {
                if(a[j]<v[i]) {
                    if(pre!=j-1) {
                        kq++;
                        pre=j;
                    }
                }
            }
        }
        cout << kq << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("sanha.inp", "r", stdin);
    freopen("sanha.out", "w", stdout);
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    soup();
}
/*
8 5
1 4 1 2 4 2 3 2
3 4
1 5
2 6
4 7
1 8
*/
