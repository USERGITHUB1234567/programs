#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,x;
const int de=1000;
int a[1001],d[2001],tr[2001],ans[1001];
int main()
{
    cin >> n >> x;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i]-=x;
    }
    int m=*max_element(a+1,a+1+n)+x,mi=*min_element(a+1,a+1+n)+x;
    if(m<x or mi>x) {
        cout << "NO";
        return 0;
    }
    memset(d,-1,sizeof(d));
    queue<int>q;
    for(int i=1; i<=n; i++) {
        d[a[i]+de]=1;
        tr[a[i]+de]=i;
        q.push(a[i]);
    }
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        if(u==0) break;
        for(int i=1; i<=n; i++) {
            int v=u+a[i];
            if(v<-1000 or u>1000 or d[v+de]!=-1) continue;
            d[v+de]=d[u+de]+1;
            q.push(v);
            tr[v+de]=i;
        }
    }
    cout << "YES\n";
    int cur=0;
    do {
        ans[tr[cur+de]]++;
        cur-=a[tr[cur+de]];
    }while(cur!=0);
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
}
