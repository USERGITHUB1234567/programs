#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
const int maxn=300005;
int n,k,a[maxn],f[maxn],kq=0;
vector<pair<int,int>>re[maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    map<int,int>mp;
    int l=1, r=1;
    int m=0;
    for(l,r; r<=n; r++) {
        mp[a[r]]++;
        m=max(m,mp[a[r]]);
        while(r-l+1-m>k) {
            mp[a[l]]--;
            if(mp[a[l]]==0) mp.erase(a[l]);
            l++;
        }
        kq=max(kq, r-l+1); 
    }
    cout << kq;
    //f[1]=1;
    /*map<int,int>mp;
    vector<pair<int,int>>p;
    map<int,vector<pair<int,int>>>stor;
    int d=1;
    for(int i=2; i<=n; i++) {
        if(a[i]==a[i-1]) {
            d++;
            mp[a[i]]=i;
        }
        else {
            stor[a[i-1]].push_back({i-mp[a[i-1]], d});
            d=1;
        }
    }
    stor[a[n]].push_back({n-mp[a[n]], d});
    int q=1;
    for(auto it:stor) {
        re[q]=it.second;
        q++;
    }
    for(int i=1; i<=q; i++) {
       int l=0,r=0,cur=0,sum=re[i][0].first;
        while(r<re[i].size()) {
            r++;
            sum+=re[i][r].first;
            cur+=re[i][r].second;
            while(cur>k) {
                cur-=re[i][l+1].first;
                sum-=re[i][l].first;
                l++;
            }
            kq=max(kq,sum);
        }
    }
    cout << kq;*/
}