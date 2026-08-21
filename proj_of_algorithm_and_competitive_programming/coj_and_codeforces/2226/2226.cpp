#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,q;
struct line
{
    int a,b;
}li[100005];
vector<line>convex;
bool cmp(line a, line b)
{
    return (a.a>b.a) || (a.a==b.a && a.b<b.b);
}
bool bad(line l1, line l2, line l3)
{
    return (long double)(l3.b-l1.b)/(l1.a-l3.a)<(long double)(l2.b-l1.b)/(l1.a-l2.a);
}
void add(line l)
{
    if(convex.size()>0 && convex.back().a==l.a && convex.back().b<=l.b) return;
    if(convex.size()>0 && convex.back().a==l.a && convex.back().b>l.b) convex.pop_back();
    convex.push_back(l);
    while(convex.size()>=3 && bad(convex[convex.size()-3],convex[convex.size()-2],convex[convex.size()-1])) convex.erase(convex.end()-2);
}
long long query(long long x)
{
    int l=0,r=convex.size()-1;
    while(l<r) {
        int c=(l+r)>>1;
        if(convex[c].a*x+convex[c].b<convex[c+1].a*x+convex[c+1].b) r=c;
        else l=c+1;
    }
    return convex[l].a*x+convex[l].b;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> li[i].a >> li[i].b;
    }
    sort(li+1,li+1+n,cmp);
    for(int i=1; i<=n; i++) {
        add(li[i]);
    }
    cin >> q;
    for(int i=1; i<=q; i++) {
        long long x;
        cin >> x;
        cout << query(x) << "\n";
    }
}
