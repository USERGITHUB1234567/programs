#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define int long long
using namespace std;
const int maxn=300005,maxh=1000006;
int n,k,h[maxn],res[maxn],mau[maxn];
pair<int,int>p[maxn];
void soup1() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(h[i]%h[j]==k) res[i]++;
        }
    }
    for(int i=1; i<=n; i++) cout << res[i] << " ";
}
vector<int>divs[maxh];
void soupfull() {
    map<int,int>cnt;
    for(int i=1; i<=n; i++) {
        p[i]={h[i],i};
        mau[i]=h[i];
    }
    int m=*max_element(mau+1,mau+1+n);
    sort(p+1,p+1+n);
    sort(mau+1,mau+1+n);
    for(int i=1; i<=n; i++) cnt[h[i]]++;
    for(int i=1; i<=n; i++) {
        if(p[i].first<k) res[p[i].second]=0;
        else if(p[i].first==k) {
            res[p[i].second]=(n-(upper_bound(mau+1,mau+1+n,p[i].first)-mau))+1;
        }
        else {
            int t=p[i].first-k;
            for(int j=1; j*j<=t; j++) {

                if(t%j==0) {
                    if(j>k) res[p[i].second]+=cnt[j];
                    if(j*j!=t && t/j>k) res[p[i].second]+=cnt[t/j];
                }
            }
        }
    }
    if(k==0) for(int i=1; i<=n; i++) res[i]--;
    for(int i=1; i<=n; i++) cout << res[i] << " ";
}
int cnt[maxh];
void soup() {
    int d=0;
    for(int i=1; i<=n; i++) {
        cnt[h[i]]++;
        if(h[i]>k) d++;
    }
    for(int i=1; i<=n; i++) {
        if(h[i]<k) res[i]=0;
        else if(h[i]==k) res[i]=d;
        else {
            int t=h[i]-k;
            for(int j=1; j*j<=t; j++) {
                if(t%j==0) {
                    if(j>k) res[i]+=cnt[j];
                    if(t/j>k && j*j!=t) res[i]+=cnt[t/j];
                }
            }
        }
    }
    if(k==0) for(int i=1; i<=n; i++) res[i]--;
    for(int i=1; i<=n; i++) cout << res[i] << " ";
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> h[i];
    soupfull();
}