#include <bits/stdc++.h>
using namespace std;
int n,x[300001],y[300001];
void sub2()
{
    map<int,int>cnx,cny;
    for(int i=1; i<=n; i++) {
        cnx[x[i]];
        cny[y[i]];
    }
    long long ans=0;
    for(int i=1; i<=n; i++) {
        ans+=1LL*(cnx[x[i]]-1)*(cny[y[i]]-1);
    }
    cout << ans;
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    sub2();
    return 0;
}
