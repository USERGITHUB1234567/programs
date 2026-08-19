#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=200005,inf=INT_MAX;
int n,m,a[maxn],cnt[maxn];

void soup1() {
    int mi=inf,kq=0;
    bool mk[n+5][m+5];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=a[i]; j++) {
            if(i&1) mk[i][j]=true;
            else mk[i][m-j+1]=true;
        }
    }
    for(int i=1; i<=m; i++) {
        int d=0;
        for(int j=1; j<=n; j++) {
            if(mk[j][i]) d++;
        }
        if(d<mi) {
            kq=i;
            mi=d;
        }
    }
    cout << mi << " " << kq << "\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) cout << mk[i][j] << " ";
        cout << "\n";
    }
}
void soup2() {
    for(int i=1; i<=n; i++) {
        if(i&1) {
            cnt[1]++;
            cnt[a[i]+1]--;
        } else {
            cnt[m-a[i]+1]++;
            cnt[m+1]--;
        }
    }
    int mi=inf,kq=0,sum=0;
    for(int j=1; j<=m; j++) {
        sum+=cnt[j];
        if(sum<mi) {
            mi=sum;
            kq=j;
        }
    }
    cout << mi << " " << kq << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("raumuong")
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    soup2();
}