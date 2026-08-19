#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mod=1e9+7,maxn=10000007;
int n,k,d,f1[maxn],f2[maxn];//f1[i]: so luong so chon dc trong cach goi toi uu bac d. f2[i]:so cach chon toi uu bac d
bool rem[maxn];
int main()
{
    memset(rem,false,sizeof(rem));
    f1[0]=0;
    f2[0]=1;
    cin >> n >> k >> d;
    for(int i=1; i<=k; i++) {
        int x;
        cin >> x;
        rem[x]=true;
    }
    for(int i=1; i<=n; i++) {
        if(rem[i]) {
            f1[i]=f1[i-1];
            f2[i]=f2[i-1];
        }
        else {
            if(f1[i-1]>f1[max(i-d-1,0)]+1) {
                f1[i]=f1[i-1];
                f2[i]=f2[i-1];
            }
            else {
                if(f1[i-1]<f1[max(i-d-1,0)]+1) {
                    f1[i]=f1[max(i-d-1,0)]+1;
                    f2[i]=f2[max(i-d-1,0)];
                }
                else {
                    f1[i]=f1[i-1];
                    f2[i]=(f2[i-1]+f2[max(i-d-1,0)])%mod;
                }
            }
        }
    }
    cout << f1[n] << "\n" << f2[n];
}
