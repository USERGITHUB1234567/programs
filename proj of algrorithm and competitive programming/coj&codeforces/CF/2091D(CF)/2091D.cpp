#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int q;
    cin >> q;
    while(q--) {
        long long n,m,k;
        cin >> n >> m >> k;
        long long t=k/n;
        if(k%n!=0) t++;
        long long kq=(m-t)+1;
        long long ans=m/kq;
        //cout << kq << " " << t << " ";
        //if((m%kq)!=0) ans++;
        cout << ans << "\n";
    }
}
