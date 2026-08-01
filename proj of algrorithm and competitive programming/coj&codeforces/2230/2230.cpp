#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005,maxk=11;
struct line
{
    long long a,b;
};
vector<line>hull[maxk];
long long n,k,f[maxn][maxk],a[maxn],s1[maxn],s2[maxn],cr;
bool bad(line l1, line l2, line l3)
{
    return (long double)(l3.b-l1.b)/(l1.a-l3.a)<(long double)(l2.b-l1.b)/(l1.a-l2.a);
}
void add(line l)
{
    if(!hull[cr].empty() && hull[cr].back().a==l.a && hull[cr].back().b<=l.b) return;
    if(!hull[cr].empty() && hull[cr].back().a==l.a && hull[cr].back().b>l.b) hull[cr].pop_back();
    hull[cr].push_back(l);
    while(hull[cr].size()>=3 && bad(hull[cr][hull[cr].size()-3],hull[cr][hull[cr].size()-2],hull[cr][hull[cr].size()-1])) hull[cr].erase(hull[cr].end()-2);
}
long long query(long long x)
{
    int l=0, r=hull[cr].size()-1;
    while(l<r) {
        int mid=(l+r)>>1;
        long long v1=hull[cr][mid].a*x+hull[cr][mid].b,v2=hull[cr][mid+1].a*x+hull[cr][mid+1].b;
        if(v1>v2) l=mid+1;
        else r=mid;
    }
    return hull[cr][l].a*x+hull[cr][l].b;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        s1[i]=s1[i-1]+a[i];
        s2[i]=s2[i-1]+i*a[i];
    }
    for(int i=1; i<=n; i++) {
        f[i][1]=s2[i]-s1[i];
    }
    f[0][1]=0;
    for(int j=2; j<=k; j++) {
        cr=j;
        int p=j-1;
        line l;
        l.a=-(p+1);
        l.b=f[p][j-1]+(p+1)*s1[p]-s2[p];
        add(l);
        p++;
        for(int i=j; i<=n; i++) {
            while(p<i) {
                line l;
                l.a=-(p+1);
                l.b=f[p][j-1]+(p+1)*s1[p]-s2[p];
                add(l);
                p++;
            }
            f[i][j]=s2[i]+query(s1[i]);
        }
    }
    cout << f[n][k];
}
