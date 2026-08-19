#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=100005;
int n,f[maxn],trace[maxn];
pair<pair<int,int>,int>rec[maxn];
bool check(pair<int,int>a, pair<int,int>b) {
    return (a.fi<=b.fi && a.se<=b.se) || (a.fi<=b.se && a.se<=b.fi);
}
void soup1() {
    for(int i=1; i<=n; i++) {
        f[i]=1;
        for(int j=1; j<i; j++) {
            if(check(rec[j].fi,rec[i].fi)) {
                f[i]=max(f[i],f[j]+1);
                trace[i]=j;
            }
        }
    }
    cout << *max_element(f+1,f+1+n) << "\n";
    int p=max_element(f+1,f+1+n)-f;
    vector<int>ans;
    while(p) {
        //cout << rec[p].se << " ";
        ans.push_back(rec[p].se);
        p=trace[p];
    }
    reverse(all(ans));
    for(int x:ans) cout << x << " ";
}
void soupfull() {
    vector<int> hcn,id;
    for (int i=1; i<=n; i++) {
        int d=rec[i].first.second;
        auto it=upper_bound(hcn.begin(), hcn.end(), d);
        int len=it-hcn.begin();
        if (it==hcn.end()) {
            hcn.push_back(d);
            id.push_back(i);
        }
        else {
            *it=d;
            id[len]=i;
        }
        trace[i]=(len>0?id[len-1]:0);
    }
    cout << hcn.size() << "\n";
    vector<int> ans;
    for (int p=id.back(); p!=0; p=trace[p]) {
        ans.push_back(rec[p].second);
    }
    reverse(ans.begin(), ans.end());
    for (int x:ans) 
        cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) {
        int r,d;
        cin >> r >> d;
        if(r<d) swap(r,d);
        rec[i]={{r,d},i};
    }
    sort(rec+1,rec+1+n);
    soupfull();

}