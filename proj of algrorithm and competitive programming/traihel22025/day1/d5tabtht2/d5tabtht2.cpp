#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
using namespace std;
#define all(x) x.begin(),x.end()
#define eb emplace_back
typedef long long ll;
const int maxn=222;
int n,k,a[maxn][maxn];
bool mk[maxn];
void soup1() {
    if(n&1) {
        a[1][n-1]=1;
        a[n][n]=1;
        for(int i=1; i<=n; i++) a[i][n-i+1]=2;
        for(int i=1; i<n-1; i++) a[i+1][i]=1;
    }
    else {
        for(int i=1;i<=n;i++) a[i][i]=1;
        for(int i=1;i<=n;i++) a[i][n-i+1]=2;
    }
}
void soup2() {
    soup1();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i][j]==0 && !mk[j]) {
                a[i][j]=3;
                mk[j]=true;
                break;
            } 
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    if(k==2) soup1();
    else soup2();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) cout << a[i][j] << " ";
        cout << "\n";
    }

}