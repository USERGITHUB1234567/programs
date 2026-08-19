/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,sl=0,t=0;
    cin >> n;
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) {
            if(i*i!=n) {
                sl+=2;
                t+=n/i;
                t+=i;
            }
            else {
                t+=i;
                sl++;
            }
        }
    }
    t+=1;
    t+=n;
    cout << sl+2 << " " << t;
}*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll n, sl = 0, t = 0;
    cin >> n;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            if(i * i != n) {
                sl += 2;
                t += n / i + i;
            }
            else {
                sl++;
                t += i;
            }
        }
    }
    t += 1 + n;
    cout << sl + 2 << " " << t;
}
