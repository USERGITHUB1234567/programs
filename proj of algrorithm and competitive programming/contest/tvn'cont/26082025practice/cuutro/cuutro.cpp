#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int maxn=100005;
int n;
long long a[maxn];
void soup2()
{
    /*long long kq=0;
    int k=0,l=0;
    for(int i=1; i<=n; i++) {
        if(k==2) {
            k=0;
            l^=1;
        }
        if(l&1)kq+=a[i];
        else kq-=a[i];
        k++;
    }
    cout << kq;*/
    if(n==1) {
        cout << 0;
        return;
    }
    else if(n<=3) cout << a[n]-a[1];
    else cout << a[n]+a[n-1]-a[1]-a[2];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("cuutro")
    cin >> n;
    bool kts2=true;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(a[i]!=i) kts2=false;
    }
    if(kts2) soup2();
}
