#include <bits/stdc++.h>
using namespace std;
int t;
void soup1(long long m)
{
    long long d=0;
    long long n=m*(m+1)*(m+2);
    for(int i=2; i<n; i++) {
        if((n*n)%i==0 && n%i!=0) d++;
    }
    cout << d << "\n";
}
map<long long, long long>pt(long long m)
{
    map<long long, long long>mp;
    for(int i=m; i<=m+2; i++) {
        int n=i;
        for(int j=2; j*j<=i; j++) {
            while(n%j==0) {
                long long t=i/j;
                mp[t]++;
                n/=j;
            }
        }
        if(n>0) mp[n]++;
    }
    return mp;
}
void soup2()
{

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> t;
    while(t--) {
        long long m;
        cin >> m;
        if(m<=1000) soup1(m);

    }
}
