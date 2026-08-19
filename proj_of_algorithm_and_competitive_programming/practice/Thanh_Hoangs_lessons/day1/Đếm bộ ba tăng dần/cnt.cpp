#include <bits/stdc++.h>
using namespace std;
const int maxn=10004;
int n;
long long w,l[maxn],r[maxn];
pair<long long,int>a[maxn];
int main(int argc, char** argv) {
    cin >> n >> w;
    if(n<3) {cout << 0;return 0;}
    for(int i=1; i<=n; ++i) {cin >> a[i].first;a[i].second=i;}
    sort(a+1,a+1+n);
    long long ans=0;
    for(int i=2; i<n; ++i) {
        int szl=0,szr=0;
        long long range=w-a[i].first;
        for(int j=1; j<=n; ++j) {
            if(a[j].first<a[i].first && a[j].second<a[i].second) l[++szl]=a[j].first;
            else if(a[j].first>a[i].first && a[j].second>a[i].second) r[++szr]=a[j].first;
        }
        int pl=1,pr=szr;
        while(pl<=szl && pr>=1) {
            if(l[pl]+r[pr]<=range) {ans+=pr;++pl;}
            else --pr;
        }
    }
    cout << ans;
}