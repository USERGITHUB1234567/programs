#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct paint
{
    int a,b,c,d;
    char e;
};
paint p[300005];
char op[1005][1005];
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) cin >> op[i][j];
    for(int i=1; i<=k; i++) {
        cin >> p[i].a >> p[i].b >> p[i].c >> p[i].d >> p[i].e;
    }

}
