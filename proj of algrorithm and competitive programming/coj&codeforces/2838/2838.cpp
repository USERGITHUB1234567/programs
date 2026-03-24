#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long a,b,n,m;
        cin >> a >> b >> n >> m;
        if(b*(m+1)<a) {
            cout << n*b << "\n";
            continue;
        }
        else {
            long long re=0;
            re+=(n/(m+1))*a;
            if(n%(m+1)!=0) {
                if(b*(n%(m+1))<a) re+=b*(n%(m+1));
                else re+=a;
            }
            cout << re << "\n";
        }
    }
}
