#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=222;
int n,a[maxn][maxn];
bool mk[maxn];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    if(n&1)
    {
        a[1][n-1]=1;
        a[n][n]=1;
        for(int i=1;i<=n;++i)
            a[i][n-i+1]=2;
        for(int i=1;i<n-1;++i)
            a[i+1][i]=1;
    }
    else
    {
        for(int i=1;i<=n;++i)
            a[i][i]=1;
        for(int i=1;i<=n;++i)
            a[i][n-i+1]=2;
    }

    /*bool kt=true;
    for(int i=1; i<=n; i++) {
        bool ck=false;
        for(int j=n; j>=1; j--) {
            if(a[i][j]==1) continue;
            if(!mk[j])  {
                a[i][j]=2;
                mk[j]=true;
                ck=true;
                break;
            }
            
        }
        if(!ck) {
            kt=false;
            break;
        }
    }
    if(!kt) {
        cout << -1;
        return 0;
    }*/
   //for(int i=1; i<=n; i++) cout << mk[i] << " " ;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }

}