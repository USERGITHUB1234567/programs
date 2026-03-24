#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=200005;
int a[maxn],b[maxn],kq,n,m;
vector<int>da,db;
int pa[maxn],pb[maxn];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(a[i]==0) da.push_back(i);
        pa[i]=pa[i-1]+(a[i]==1);
    }
    cin >> m;
    for(int i=1; i<=m; i++) {
        cin >> b[i];
        if(b[i]==0) db.push_back(i);
        pb[i]=pb[i-1]+(b[i]==1);
    }
    kq=min(pa[n],pb[m]);
    int mi=min(da.size(),db.size());
    for(int i=0; i<mi; i++) {
        int oa=da[i],ob=db[i],a1=pa[n]-pa[oa],b1=pb[m]-pb[ob];
        int x=min(a1,b1);
        x+=i+1;
        kq=max(kq,x);
    }
    cout << kq;
}
