#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=200005;
int n,q,a[maxn];
void soup1() {
    while(q--) {
        int l,r;
        cin >> l >> r;
        vector<int>v;
        for(int i=1; i<=n; i++) {
            if(i>=l && i<=r) continue;
            v.push_back(a[i]);
        }
        int t=v.size();
        int tv=(t+1)/2;
        sort(v.begin(),v.end());
        cout << v[tv-1] << "\n";
        //for(int i:v) cout << i << " ";
        //cout << "\n";
    }
}
void soup2() {
    while(q--) {
        int l,r;
        cin >> l >> r;
        int tv=((n-(r-l+1))+1)/2;
        if(tv>=l) cout << a[r+tv-l+1] << "\n";
        else cout << a[tv] << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("tv")
    cin >> n >> q;
    bool ck=true;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(a[i]<a[i-1]) ck=false;
    }
    if(n<=5000 && q<=5000) {
        soup1();
        return 0;
    }
    soup2();
}