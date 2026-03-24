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
const ll inf=LLONG_MAX;
int n;
long long a[maxn];
string conv(long long x)
{
    string s="";
    while(x>0) {
        if(x&1) s='1'+s;
        else s='0'+s;
        x>>=1;
    }
    return s;
}
struct trie
{
    int tr[maxn][2],cur=0,mn[maxn];
    trie()
    {
        for(int i=0; i<maxn; i++) mn[i]=inf;
    }
    void add(string &s)
    {
        int pos=0;
        for(char c:s) {
            int j=c-'a';
            if(!tr[pos][j]) tr[pos][j]=++cur;
            pos=tr[pos][j];
        }
    }
    long long query()
    {

    }

};
void soup1()
{
    long long kq=0;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            kq=max(kq,a[i]^a[j]);
        }
    }
    cout << kq;
}
void souprua()
{
    ll mx=0,p,res=0;
    for(int i=1; i<=n; i++) {
        if(a[i]>mx) {
            mx=a[i];
            p=i;
        }
    }
    for(int i=1; i<=n; i++) {
        if(i==p) continue;
        res=max(res,mx^a[i]);
    }
    cout << res;
}
vector<ll>rua2;
void souprua2()
{
    long long res=0;
    for(ll i:rua2) {
        for(int j=1; j<=n; j++) res=max(i^a[j],res);
    }
    cout << res;
}
void soup2()
{

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    file("xor")
    cin >> n;
    ll ktm=0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        ll s=conv(a[i]).size();
        if(s>ktm) ktm=s;
    }

    for(int i=1; i<=n; i++) {
        if(conv(a[i]).size()==ktm) rua2.pb(a[i]);
    }
    if(n<=5000) {
        soup1();
        cout << "\n";
        return 0;
    }
    if(rua2.size()*n<=1000006) {
        souprua2();
        cout << "\n";
        return 0;
    }
    souprua();
}
