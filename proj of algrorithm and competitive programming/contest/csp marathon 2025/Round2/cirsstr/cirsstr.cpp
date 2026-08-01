#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
using namespace std;

string t1, t2;
char s1[200005], s2[200005];
int n, m, p1[200005], p2[200005], h1_s[200005], h1_p[200005], h2_s[200005], h2_p[200005];
const long long mod1=1e9+7, mod2=1e9+9, base=91138233;

void build_hash(char* t, int* h1, int* h2, int len)
{
    h1[0]=h2[0]=0;
    for(int i=1;i<=len;i++)
    {
        int v=(t[i-1]-'a'+1);
        h1[i]=(h1[i-1]*base+v)%mod1;
        h2[i]=(h2[i-1]*base+v)%mod2;
    }
}

pair<int,int> get_hash(int* h1, int* h2, int l, int r)
{
    int x1=(h1[r]+mod1-(h1[l-1]*p1[r-l+1])%mod1)%mod1;
    int x2=(h2[r]+mod2-(h2[l-1]*p2[r-l+1])%mod2)%mod2;
    return {x1,x2};
}

bool check(int l)
{
    unordered_set<int> st;
    for(int i=1;i<=n;i++)
    {
        pair<int,int> g=get_hash(h1_s, h2_s, i, i+l-1);
        int ke=(g.fi<<32)^g.se;
        st.insert(ke);
    }
    for(int i=1;i<=m;i++)
    {
        pair<int,int> g=get_hash(h1_p, h2_p, i, i+l-1);
        int ke=(g.fi<<32)^g.se;
        if(st.count(ke)) return true;
    }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t1 >> t2;
    n=t1.size();
    m=t2.size();
    for(int i=0;i<n;i++)
        s1[i]=s1[i+n]=t1[i];
    for(int i=0;i<m;i++)
        s2[i]=s2[i+m]=t2[i];
    int sizes=2*n, sizep=2*m;
    p1[0]=p2[0]=1;
    int k=max(sizes,sizep);
    for(int i=1;i<=k;i++)
    {
        p1[i]=(p1[i-1]*base)%mod1;
        p2[i]=(p2[i-1]*base)%mod2;
    }
    build_hash(s1,h1_s,h2_s,sizes);
    build_hash(s2,h1_p,h2_p,sizep);
    int l=0, r=min(n,m);
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout << l;
    return 0;
}
