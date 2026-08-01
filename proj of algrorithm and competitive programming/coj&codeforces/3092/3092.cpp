#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,m;
pair<int,int> s[100005];
bool mark[100005];
struct pic
{
    int a,b,l;
    vector<int>v;
}p[100005];
int re[100005];
int main()
{
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> s[i].first;
        s[i].second=i;
    }
    sort(s+1,s+1+n);
    for(int i=1; i<=m; i++) {
        cin >> p[i].a >> p[i].b >> p[i].l;
        for(int i=1; i<=p[i].l; i++) {
            int x;
            cin >> x;
            p[i].v.push_back(x);
            mark[x]=true;
        }

    }
}
