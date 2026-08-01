#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=10000007;
bool nt[maxn],th[maxn];
int pre[maxn];
void snt()
{
    memset(nt,true,sizeof(nt));
    nt[0]=nt[1]=false;
    for(int i=2; i*i<maxn; i++) {
        if(nt[i]) {
            int j=i*i;
            while(j<=maxn) {
                nt[j]=false;
                j+=i;
            }
        }
    }
}
void setup()
{
    for(int b=0; ;b++) {
        int b4=b*b*b*b;
        if(b4>=maxn) break;
        for(int a=0; ;a++) {
            int a4=a*a;
            int x=b4+a4;
            if(x>=maxn) break;
            else th[x]=true;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    snt();
    setup();
    for(int i=0; i<maxn; i++) {
        if(th[i]&&nt[i]) pre[i]=pre[i-1]+1;
        else pre[i]=pre[i-1];
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << pre[n] << "\n";
    }
}
