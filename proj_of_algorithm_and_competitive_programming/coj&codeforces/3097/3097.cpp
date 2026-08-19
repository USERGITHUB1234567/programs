#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, m;
pair<long long, long long> p[200005];
long long kq = 0, t = 0;
long long tl(long long x) {
    return x*(x+1)/2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=m; i++)
        cin >> p[i].first;
    for (int i=1; i<=m; i++){
        cin >> p[i].second;
        t+=p[i].second;
    }
    sort(p+1, p+m+1);
    if(p[1].first!=1 || t!=n){
        cout << -1;
        return 0;
    }
    for (int i=1; i<=m; i++){
        if(p[i].second>n-p[i].first+1){
            cout << -1;
            return 0;
        }
    }
    long long sm=0;
    for (int j=1; j<=m; j++){
        sm+=p[j].second;
        long long L=p[j].first,R=(j<m?p[j+1].first-1:n-1);
        if(L>R) continue;
        long long ln=R-L+1;
        long long sr=tl(R)-tl(L - 1);
        if(sm<=L){
            kq+=(sr-sm*ln);
        } else if(sm>=R){
            kq+=(sm*ln-sr);
        } else {
            long long s1=(sm-L)*(sm-L+1)/2;
            long long s2=(R-sm)*(R-sm+1)/2;
            kq+=(s1+s2);
        }
    }
    cout << kq;
    return 0;
}
