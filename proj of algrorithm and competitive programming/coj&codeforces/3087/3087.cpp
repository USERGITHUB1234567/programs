#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,h[200005],q;
void soup(int l, int r)
{
    int mi=min(l,r),m=h[r],d=0;
    for(int i=r+1; i<=n; i++) {
        if(h[i]>=m) {
            m=h[i];
            d++;
        }
    }
    cout << d << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> h[i];
    /*if(q<=1000) {
        while(q--) {
            int l,r;
            cin >> l >> r;
            soup(l,r);
        }
    }*/
    vector<vector<pair<int,int>>>qu(n);
    for(int i=0; i<q; i++) {
        int l,r;
        cin >> l >> r;
        l--; r--;
        qu[l].push_back({r,i});
    }
    vector<int>ans(q,0);
    vector<int>st;
    for (int l=n-1; l>=0; l--){
        for (auto p:qu[l]){
            int r=p.first;
            int i=p.second;
            int pos=lower_bound(st.begin(), st.end(), -r)-st.begin();
            ans[i]=pos;
        }
        while (!st.empty() && h[-st.back()]<h[l]) st.pop_back();
        st.push_back(-l);
    }
    for (int i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
