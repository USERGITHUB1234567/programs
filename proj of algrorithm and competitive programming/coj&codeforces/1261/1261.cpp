#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=200005;
int a[maxn],cr[maxn],n;
set<int>st;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    int q;
    cin >> q;
    for(int i=1; i<=n; i++) st.insert(i);
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            int x,p;
            cin >> p >> x;
            auto it=st.lower_bound(p);
            while(x>0 && it!=st.end()) {
                int id=*it,cl=a[id]-cr[id];
                if(x>=cl) {
                    cr[id]=a[id];
                    x-=cl;
                    it=st.erase(it);
                }
                else {
                    cr[id]+=x;
                    x=0;
                }
            }
        }
        else {
            int k;
            cin >> k;
            cout << cr[k] << "\n";
        }
    }
}
