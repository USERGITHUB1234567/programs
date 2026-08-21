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
int main(int argc, char** argv) {
    freopen("coats.inp", "r", stdin);
    freopen("coats.out", "w", stdout);
    cin >> n;
    for(int i=1; i<n; ++i) cin >> a[i];
    soup1::implement();
}
/*
8
5 1 9 1 9 9 9

10
6 4 2 7 1 8 3 9 5
*/