#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int a[200001];
void pt()
{

}
bool kt(int n)
{

}
void sub1(int n)
{
    for(int i=1; i<=n; i++) {
        bool c=1;
        for(int ii=0; ii<=n/i; ii+=n/i) {
            for(int j=ii; j<=i+n/i or j<n; j++) {
                for(int k=j; k<=i+n/i; k++) {
                    if(k==n-1) break;
                    long long t=a[j]*a[k];
                    int ts=sqrt(t);
                    if(ts*ts==t) c=0;
                }
            }
        }
        if(c==1) {
            cout << i;
            break;
        }
    }
    cout << n;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("spli.inp", "r", stdin);
    freopen("spli.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    if(n<100) {
        sub1(n);
        return 0;
    }
    cout << n;
}
