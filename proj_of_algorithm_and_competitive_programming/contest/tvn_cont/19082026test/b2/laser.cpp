#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
int l,r;
vector<int>door[maxn];
namespace soup2{
    bool check() {
        for(int i=1; i<=r; ++i) if(door[i].size()>1) return false;
        return true;
    }
    void implement() {
        int mx=0;
        for(int i=1; i<=r; ++i) mx=max(mx,door[i][0]);
        int ans=0;
        if(mx>(l>>1)) ans=(mx)-(l-mx);
        cout << ans;
    }
}
namespace souptrau{
    void implement() {
        int ans=0;
        for(int i=1; i<=l; ++i) {
            bool ck=true;
            for(int j=1; j<=r; ++j) {
                int sum1=0,sum2=0;
                bool swit=false;
                for(int t=0; t<door[j].size(); ++t) {
                    if(sum1+door[j][t]>=i) swit=true;
                    if(!swit) sum1+=door[j][t];
                    else sum2+=door[j][t];
                }
                //cout << sum1 << ' ' << sum2 << '\n';
                if(l+1-sum2<=i) {ck=false;break;} 
            }
            ans+=(ck^1);
            //cout << ck << '\n';
        }
        cout << ans;
    }
}
namespace soupfull{
    void implement() {
        vector<pair<int,int>>store;
        for(int i=1; i<=r; ++i) {
            int len=accumulate(door[i].begin(),door[i].end(),0),sum=0;
            for(int j=0; j<door[i].size(); ++j) {
                int left=sum,right=l+1-len+door[i][j]+sum,cur=door[i][j];
                int t1=left+cur,t2=right-cur;
                if(t2<=t1) store.push_back({t2,t1});
                sum+=cur;
            }
        }
        sort(store.begin(),store.end());
        int ans=0,mx=0,st=0;
        for(int i=0; i<store.size(); ++i) {
            auto[u,v]=store[i];
            if(u>mx) {
                if(st)ans+=mx-st+1;
                st=u;
                mx=v;
            }else mx=max(mx,v);
        }
        if(st)ans+=mx-st+1;
        cout << ans;
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("laser.inp", "r", stdin);
    freopen("laser.out", "w", stdout);
    cin >> l >> r;
    for(int i=1; i<=r; ++i) {
        int x;cin >> x;
        door[i].reserve(x);
        for(int j=1,t; j<=x; ++j) {
            cin >> t;
            door[i].push_back(t);
        }
    }
    //if(soup2::check()) soup2::implement();
    soupfull::implement();
}
/*
11 3
2 2 3
1 7
2 4 1

10 3
3 1 5 1
4 2 2 3 1
3 1 6 2

*/
