#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
int n,m,a[maxn],b[maxn];
void soup1()
{
    for(int i=1; i<=m; i++) {
        int t;
        cin >> t;
        if(t==1) {
            int x,y,k;
            cin >> x >> y >> k;
            for(int j=0; j<k; j++) {
                b[y+j]=a[x+j];
            }
        }
        else {
            int p;
            cin >> p;
            cout << b[p] << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    soup1();
}
