#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

mt19937_64 generator(time(0));
int rnd(int a,int b)
{
    return a+generator()%(b-a+1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n=1e3,m=0;
    int p[100001];//p[i] la nut cha cua nut i
    for(int i=2; i<=n; i++)
        p[i]=rnd(1,i-1);
    int perm[100001];
    for(int i=1; i<=n; i++)
        perm[i]=i;
    srand(time(0));
    random_shuffle(perm+1,perm+1+n);
    srand(time(0));
    cout << n << " " << m << "\n";
    for(int i=2; i<=n; i++) {
        int u=perm[i], v=perm[p[i]];
        if(rnd(0,1)==0)
            cout << u << " " << v << "\n";
        else cout << v << " " << u << "\n";
    }
    for(int i=1; i<=m; i++) {
        int v=rnd(1,n), d=rnd(0,n/10000);
        cout << v << " " << d << "\n";
    }
    return 0;
}
