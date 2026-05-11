#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=1000006;
struct line
{
    long long a,b;
};
long long a,b,c,x[maxn],f[maxn],s[maxn],n;
vector<line>hull;
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
long long query(long long x) {
    int l=0, h=hull.size()-1;
    while (l<h) {
        int mid=(l+h)>>1;
        if (hull[mid].a*x+hull[mid].b<=hull[mid+1].a*x+hull[mid+1].b)
            l=mid+1;
        else
            h=mid;
    }
    return hull[l].a * x + hull[l].b;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> a >> b >> c;
    for(int i=1; i<=n; i++) {
        cin >> x[i];
        s[i]=s[i-1]+x[i];
    }
    add({-2*a*s[0],f[0]+a*s[0]*s[0]-b*s[0]});
    for(int i=1; i<=n; i++) {
        long long t=query(s[i]);
        f[i]=a*s[i]*s[i]+b*s[i]+c+t;
        add({-2*a*s[i], f[i]+a*s[i]*s[i]-b*s[i]});

    }
    cout << f[n];
}
