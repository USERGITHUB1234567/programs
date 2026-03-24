#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k,t=0;
    cin >> n >> k;
    long long a[n+1];
    for(long long i=1; i<=n; i++) {
        cin >> a[i];
        a[i]-=k;
        //cout << a[i] << " ";
    }
    long long p,m=0;
    map<long long,long long>mp;
    mp[-k]=0;
    t=-k;
    for(long long i=1; i<=n; i++) {
        t+=a[i];
        if(mp[t]==0 and t!=-k) {
            mp[t]=i;
        }
        else {
            m=max(m,i-mp[t]);
            p=mp[t]+1;
        }
        //cout << t << " " << m <<" " << mp[t] << endl;
    }
    //cout << endl;
    if(m==0) cout << 0;
    else cout << m << " " << p;
}
