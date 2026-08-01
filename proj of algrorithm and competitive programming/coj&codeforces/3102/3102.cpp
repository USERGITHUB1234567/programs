#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long INF=(long long)4e18;
long long n,k,x,t[102];
long long m=0,a[10101],prv[10101],f[10101][102];
void soup1(){
    long long h=t[1],ans=0;
    for(int i=1; i<=n; i++){
        if(h<t[i]) h=t[i];
        ans+=h-t[i];
        h+=x;
    }
    cout << ans;
}
void souplo(){
    cout << 0;
}
void soup234(){
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++) a[++m]=t[i]+j*x;
    sort(a+1,a+m+1);
    m=unique(a+1,a+m+1)-(a+1);
    for(int i=1; i<=m; i++){
        long long target=a[i]-x;
        int p=upper_bound(a+1,a+m+1,target)-(a+1);
        prv[i]=p;
    }
    for(int i=0; i<=m; i++)
        for(int j=0;j<=n;j++) f[i][j]=(j==0?0:INF);
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++){
            f[i][j]=min(f[i][j],f[i-1][j]);
            long long sum=0;
            for(int c=1; c<=k; c++){
                if(t[j-c+1]>a[i] || j-c+1<1) break;
                sum+=a[i]-t[j-c+1];
                long long prev=(prv[i]>=1?f[prv[i]][j-c]:(j-c==0?0:INF));
                f[i][j]=min(f[i][j],prev+sum);
            }
        }
    }
    long long ans=INF;
    for(int i=1; i<=m; i++) ans=min(ans,f[i][n]);
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k >> x;
    for(int i=1; i<=n; i++) cin >> t[i];
    if(n==1) souplo();
    else if(k==1) soup1();
    else soup234();
    return 0;
}
