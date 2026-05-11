#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=1000006;
int n, re=0;
int a[maxn];
int vis[maxn];
bool kq[maxn];
void dfs(int s) {
    int c=s;
    vector<int> pa;
    while(vis[c]==0) {
        vis[c] = 1;
        pa.push_back(c);
        c=(c+a[c]+1)%n;
    }
    if(vis[c]==1) {
        bool m=false;
        for(int x:pa) {
            if(x==c) m=true;
            if(m) {
                if(!kq[x]) {
                    kq[x]=true;
                    re++;
                }
            }
        }
    }
    for(int x:pa) {
        vis[x]=2;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        if (vis[i]==0) {
            dfs(i);
        }
    }
    cout << re;
    return 0;
}
