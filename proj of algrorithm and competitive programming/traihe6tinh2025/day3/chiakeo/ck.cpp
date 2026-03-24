#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int base=1000000000,mb=500;
struct bint
{
    int d[mb];
    int l;
};
void init(bint &x)
{
    memset(x.d,0,sizeof(x.d));
    x.l=1;
}
void init(bint &x, int v)
{
    memset(x.d,0,sizeof(x.d));
    x.d[0]=v;
    x.l=1;
}
void add(bint &x, const bint &y)
{
    int c=0;
    int m=max(x.l,y.l);
    for(int i=0; i<m||c; i++) {
        if(i==x.l) {
            x.d[i]=0;
            x.l++;
        }
        long long cur=(long long)x.d[i]+(i<y.l?y.d[i]:0)+c;
        x.d[i]=cur%base;
        c=cur/base;
    }
}
void print(const bint &x)
{
    cout << x.d[x.l-1];
    for(int i=x.l-2; i>=0; i--) cout << setw(9) << setfill('0') << x.d[i];
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        bint ans, one;
        init(ans);
        init(one,1);
        for(int i=0,tmp=0; i<=n/a; i++, tmp=a*i) {
            for(int j=0,sum=tmp; j<=(n-tmp)/b; j++, sum=tmp+b*j) {
                int rem=n-sum;
                if(rem%c==0) add(ans,one);
            }
        }
        print(ans);
    }
}
