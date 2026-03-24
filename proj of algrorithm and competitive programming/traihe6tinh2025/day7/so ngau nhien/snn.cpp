#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=10000007;
int child[maxn][2],val[maxn],num[maxn],n,q,cnt=0;
void add(int x)
{
    int node=0;
    for(short i=30; i>=0; i--) {
        short ch=(((x)>>(i))&1);
        if(child[node][ch]==0) child[node][ch]=++cnt;
        node=child[node][ch];
        num[node]++;
    }
    val[node]=x;
}
int query(int k)
{
    int node=0,res=0;
    for(short i=30; i>=0; i--) {
        if(child[node][0]==0 || k>num[child[node][0]]) {
            k-=num[child[node][0]];
            node=child[node][1];
            res=res*2+1;
        }
        else {
            node=child[node][0];
            res=res*2;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q,t,x;
    cin >> q;
    while(q--) {
        cin >> t >> x;
        if(t==1) add(x);
        else cout << query(x) << "\n";
    }
}
