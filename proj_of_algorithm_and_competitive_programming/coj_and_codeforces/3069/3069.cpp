#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
struct pro
{
    int a,b,p;
}pr[200005];
bool cmp(pro a, pro b)
{
    return a.p>b.p;
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> pr[i].a >> pr[i].b >> pr[i].p;

}
