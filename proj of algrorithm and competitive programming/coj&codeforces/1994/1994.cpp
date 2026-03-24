#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=67,inf=LLONG_MAX;
int p,c,g,v[11],gu[5];
double ans=INT_MAX;
double x[maxn],y[maxn],d[maxn][maxn];
double dist(double a, double b, double c, double d)
{
    int t1=abs(a-c),t2=abs(b-d);
    return sqrt(t1*t1+t2*t2);
}
void ck()
{
    double mx=-1;
    for(int i=1; i<=p; i++) {
        double mn=INT_MAX;
        for(int j=1; j<=g; j++)  mn=min(mn,d[i][gu[j]]*v[i]);
        mx=max(mx,mn);
    }
    ans=min(ans,mx);
}
void dfs(int i)
{
    if(i>p) {
        ck();
        return;
    }
    for(int j=gu[i-1]+1; j<=p-(g-i); j++) {
        gu[i]=j;
        dfs(i+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //cout << "too few guards";
    cin >> p >> c >> g;
    for(int i=1; i<=p; i++) {
        char c;
        cin >> c >> x[i] >> y[i] >> v[i];
    }
    for(int i=1; i<=maxn; i++) {
        d[i][i]=0;
        for(int j=i+1; j<=maxn; j++) d[i][j]=d[j][i]=inf;
    }
    int n=p;
    for(int k=1; k<=c; k++) {
        string s;
        cin >> s;
        for(int i=0; i<s.size(); i++) {
            for(int j=i+1; j<s.size(); j++) {
                int a=s[i]-64,b=s[i]-64;
                d[a][b]=d[b][a]=dist(x[a],y[a],x[b],y[b]);
            }
        }
        int m=n;
        for(int i=0; i<s.size(); i++) {
            for(int j=i+1; j<s.size(); j++) {
                int a=s[i]-64,b=s[i]-64;
                if(v[a]>0 && v[b]>0) {
                    n++;
                    x[n]=(v[a]*x[a]+v[b]*x[b])/(v[a]+v[b]);
                    y[n]=(v[a]*y[a]+v[b]*y[b])/(y[a]+y[b]);
                }
            }
        }
        for(int i=0; i<s.size(); i++) {
            for(int j=m+1; j<=n; j++) {
                int a=s[i]-64;
                d[a][j]=d[j][a]=dist(x[a],y[a],x[j],y[j]);
            }
        }
    }
    dfs(1);
    if(ans==INT_MAX) cout << "too few guards";
    else cout << fixed << setprecision(2) << ans;
}
