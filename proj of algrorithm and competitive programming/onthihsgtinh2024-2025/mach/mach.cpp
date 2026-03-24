#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int visited[1005],marked[1005];
int n,k;
mt19937_64 generator(time(0));
int rnd(int a,int b)
{
    return a+generator()%(b-a+1);
}
void subrnd()
{
    for(int i=1; i<=n; i++) cout << rnd(0,1) << " ";
}
struct work
{
    int s,ti,c;
};
bool cmp(work a, work b)
{
    if(a.s!=b.s) return a.s<b.s;
    return a.ti<b.ti;
}
int x[1000];
int km[100000];
/*void dequy(int i)
{
    if(i>n) {
        if()
    }
    for(int j=0; j<=1; j+) {
        x[i]=j;
        dfs(i+1);
    }
}
void sub1()
{

}*/
int main()
{
    freopen("mach.inp", "r", stdin);
    freopen("mach.out", "w", stdout);
    memset(visited,-1,sizeof(visited));
    cin >> n >> k;
    work t[n+1];
    t[0].s=0;t[0].ti=0;t[0].c=0;
    for(int i=1; i<=n; i++) cin >> t[i].s >> t[i].ti >> t[i].c;
    sort(t,t+n,cmp);
    while(k--) {
        int p1=1,p2=1;
        visited[p1]=k;
        while(p2<=n) {

        }
    }
}
