#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,dist[maxn],freq[31],p10[5]={1,10,100,1000,10000};
int main(int argc, char** argv) {
    cin >> n;
    queue<int>q;
    fill(dist,dist+maxn,30);
    freq[30]=100000;
    int ans=30;
    for(int i=1; i<=n; ++i) {
        int a;cin >> a;
        if(dist[a]) {
            --freq[dist[a]];
            ++freq[0];
            q.push(a);
            dist[a]=0;
            while(!q.empty()) {
                int u=q.front();q.pop();
                int cd=dist[u],cur=u;
                for(int j=0; j<5; ++j) {
                    int d=cur%10,dx=(d+1)%10,dy=(d+9)%10;
                    int x=u-d*p10[j]+dx*p10[j];
                    int y=u-d*p10[j]+dy*p10[j];
                    if(cd+1<dist[x]) {
                        --freq[dist[x]];
                        dist[x]=cd+1;
                        ++freq[dist[x]];
                        q.push(x);
                    }
                    if(cd+1<dist[y]) {
                        --freq[dist[y]];
                        dist[y]=cd+1;
                        ++freq[dist[y]];
                        q.push(y);
                    }
                    cur/=10;
                }
            }
        }
        while(ans>0 && !freq[ans]) --ans;
        cout << ans << ' ' << freq[ans] << '\n';
    }
}
