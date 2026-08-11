#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(n) freopen(n".inp", "r", stdin); freopen(n".out", "w", stdout);
using namespace std;
const int maxn=200005;
int n,f[maxn];
pair<int,int>a[maxn];
vector<pair<int,int>>ans;
bool cmp(pair<int,int>a, pair<int,int>b) {
    return (a.first<b.first) || (a.first==b.first && a.second>b.second);
}
bool check(pair<int,int>a, pair<int,int>b) {
    return a.first<=b.first && a.second>=b.second;
}
void add(pair<int,int>p) {
    int l=0,r=ans.size()-1,mid;
    if(ans.empty() || check(ans.back(),p)) {
        ans.push_back(p);
        return;
    }
    if(check(p,ans[0])) {
        ans.insert(ans.begin(),p);
        return;
    }
    while(l<=r) {
        mid=(l+r)>>1;
        pair<int,int>cur=ans[mid];
        if(check(cur,p)) l=mid+1;
        else r=mid-1;
    }
    //ans.insert(ans.begin()+l,p);
    ans[l]=p;
}
void soup2() {
    sort(a+1,a+1+n,cmp);
    for(int i=1; i<=n; ++i) {
        f[i]=1;
        for(int j=i-1; j>=1; --j) {
            if(check(a[j],a[i])) f[i]=max(f[i],f[j]+1);
        }
    }
    cout << *max_element(f+1,f+1+n);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("ns");
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].first >> a[i].second;
    sort(a+1,a+1+n,cmp);
    for(int i=1; i<=n; ++i) add(a[i]);
    cout << ans.size();
    //cout << "\n";
    //soup2();
}
/*
6
1 4
1 7
1 6
1 5
3 5
2 5
*/