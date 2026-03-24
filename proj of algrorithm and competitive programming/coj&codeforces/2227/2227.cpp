#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=100005;
struct line
{
    long long a,b;
}li[maxn];
long long a[maxn],b[maxn],f[maxn],n;
vector<line>hull;
bool cmp(line u, line v)
{
    return (u.a>v.a) || (u.a==v.a && u.b>v.b);
}
bool bad(line l1, line l2, line l3)
{
    return (long double)(l3.b-l1.b)/(l1.a-l3.a)<(long double)(l2.b-l1.b)/(l1.a-l2.a);
}
void add(line l)
{
    if(!hull.empty() && hull.back().a==l.a && hull.back().b<=l.b) return;
    if(!hull.empty() && hull.back().a==l.a && hull.back().b>l.b) hull.pop_back();
    hull.push_back(l);
    while(hull.size()>=3 && bad(hull[hull.size()-3],hull[hull.size()-2],hull[hull.size()-1])) hull.erase(hull.end()-2);
}
long long query(long long x)
{
    int l=0, r=hull.size()-1;
    while(l<r) {
        int mid=(l+r)>>1;
        long long v1=hull[mid].a*x+hull[mid].b,v2=hull[mid+1].a*x+hull[mid+1].b;
        if(v1<=v2) r=mid;
        else l=mid+1;
    }
    return hull[l].a*x+hull[l].b;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) cin >> b[i];
    f[1]=0;
    hull.clear();
    add({b[1],f[1]});
    for(int i=2; i<=n; i++) {
        f[i]=query(a[i]);
        add({b[i],f[i]});
    }
    cout << f[n];
}
