#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n;
long long a[maxn];
namespace soup1{
    short state[20];
    long long ans;
    void backtrack(int id) {
        //cerr << id << '\n';
        if(id>=n) {
            int cur=0,cnt=0;
            long long cost=0;
            bool ck=true;
            //for(int i=1; i<n; ++i) cout << state[i] << ' ';
            //cout << '\n';
            for(int i=1; i<n; ++i) {
                if(cur==0 && !state[i]) {ck=false;break;}
                if(!state[i])--cur;
                else if(state[i]==1) {
                    cur=cnt;
                    ++cost;
                }else {
                    ++cnt;
                    cur=cnt;
                    cost+=a[i]+1;
                }
            }
            if(ck) {ans=min(ans,cost);}
            return;
        }
        for(int i=0; i<3; ++i) {
            state[id]=i;
            backtrack(id+1);
        }
    }
    void implement() {
        ans=n;
        backtrack(1);
        cout << ans;
    }
}
namespace soup2{
    long long f[1503][1503];
    void implement() {
        const long long inf=(1LL << 60);
        for(int i=0; i<n; ++i) for(int j=0; j<=n; ++j) f[i][j]=inf;
        f[0][1]=0;
        for(int i=1; i<n; ++i) {
            for(int k=0; k<i; ++k) {
                for(int j=i-k; j*j<=n; ++j) {
                    if(f[k][j]==inf || i-k>j) continue;
                    f[i][j]=min(f[i][j],f[k][j]+1);
                    f[i][j+1]=min(f[i][j+1],f[k][j]+1+a[i]);
                }
            }
        }
        long long ans=inf;
        for(int k=0; k<n; ++k)
            for(int j=1; j<=n; ++j)
                if(n-k<=j) ans=min(ans,f[k][j]);
        cout << ans;
    }
}
int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("coats.inp", "r", stdin);
    freopen("coats.out", "w", stdout);
    cin >> n;
    for(int i=1; i<n; ++i) cin >> a[i];
    soup2::implement();
}
/*
8
5 1 9 1 9 9 9

10
6 4 2 7 1 8 3 9 5
*/