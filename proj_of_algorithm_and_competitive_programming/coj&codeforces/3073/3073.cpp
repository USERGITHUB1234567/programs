#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n,x,w[50];
pair<long long,long long>f[2000006];
int main()
{
    cin >> n >> x;
    for(int i=0; i<n; i++) cin >> w[i];
    f[0]={1,0};
    for(int sub=1; sub<(1<<n); sub++) {
        f[sub]={n+1,0};
        for(int i=0; i<=n+1; i++) {
            if(((sub>>i)&1)==1) {
                auto[ride,weight]=f[sub^(1<<i)];
                if(weight+w[i]>x) {
                    ride++;
                    weight=min(weight,w[i]);
                }
                else {
                    weight+=w[i];
                }
                f[sub]=min(f[sub],{ride,weight});
            }
        }
    }
    cout << f[(1<<n)-1].first;
}
