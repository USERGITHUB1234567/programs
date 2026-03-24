#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout);
#define mkp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int maxn=5003,inf=INT_MAX;
struct charger
{
    int b,c;
}cha[maxn];
int n,m,a[maxn],used[maxn],b[maxn],pre[maxn],cnt[maxn],f2[maxn][maxn];
bool mk[maxn];
bool cmp(charger a, charger b)
{
    return (a.b<b.b)||(a.b==b.b && a.c<b.c);
}
void soup1()
{
    int vt=1,kq=0;
    for(int i=1; i<=n; i++) {
        if(used[vt]>=cha[vt].c) vt++;
        kq+=abs(a[i]-cha[vt].b);
        used[vt]++;
    }
    cout << kq;
}
void soup2lo()
{
    int kq=0;
    for(int k=1; k<=n; k++) {
        int mi=inf,pr,pc;
        for(int i=1; i<=n; i++) {
            if(mk[i]) continue;
            for(int j=1; j<=m; j++) {
                if(cnt[j]>0 && abs(a[i]-b[j])<mi) {
                    mi=abs(a[i]-b[j]);
                    pr=i;
                    pc=j;
                    //cout << a[i] << " " << b[j] << "\n";
                }
                //cout << b[j] << ' ';
            }
        }
        cnt[pc]--;
        kq+=mi;
        //cout << mi << ' ' << pr << ' ' << pc << " " << b[pc] << "\n";
        mk[pr]=true;
    }
    cout << kq;
}
void soup2()
{
    f[0][0]=0;
    for(int i=1; i<=n; i++) f[0][i]=inf;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            for(int t=max(0,j-cha[i].c); t<=j; t++) {

            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //file("robot");
    cin >> n >> m;
    int tk=0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=m; i++) {
        cin >> cha[i].b >> cha[i].c;
        tk+=cha[i].c;
        pre[i]=pre[i-1]+cha[i].c;
    }
    sort(a+1,a+1+n);
    sort(cha+1,cha+1+m,cmp);
    for(int i=1; i<=m; i++) {
        b[i]=cha[i].b;
        //cout << b[i] << ' ';
        cnt[i]=cha[i].c;
    }
    if(tk==n) {
        soup1();
        return 0;
    }
    soup2();
}
