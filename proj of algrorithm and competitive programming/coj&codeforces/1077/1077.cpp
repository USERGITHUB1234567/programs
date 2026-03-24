#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m,k,g[1003],r[1003],t1=0,t2=0;
int main()
{
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        t1+=x;
    }
    for(int i=1; i<=m; i++) {
        int x;
        cin >> x;
        t2+=x;
    }
    int t=min(t1,t2);
    int kq=k/t;
    if(k%t!=0) kq++;
    cout << kq+1;
}
