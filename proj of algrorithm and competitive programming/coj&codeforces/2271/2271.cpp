/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
const ll slpt=1e6;
ll a[slpt];
void sntplus()
{
    a[0]=a[1]=0;
    for(ll i=2; i*i<=slpt; i++) {
        if(a[i]==0) {
            ll j=i;
            while(j<slpt) {
                a[j]++;
                j+=i;
            }
        }
    }
}
int main()
{
    sntplus();
    ll n,d=0;
    cin >> n;
    for(ll i=6; i<=n; i++) {
        if(a[i]==2) d++;
        //cout << a[i] << ' ';
    }
    cout << d;
    //cout << endl;
}*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
const ll slpt = 1e6 + 1;
ll a[slpt];

void sntplus() {
    fill(a, a + slpt, 0);
    for (ll i = 2; i < slpt; i++) {
        if (a[i] == 0) {
            for (ll j = i; j < slpt; j += i) {
                a[j]++;
            }
        }
    }
}

int main() {
    sntplus();
    ll n, d = 0;
    cin >> n;
    for (ll i = 6; i <= n; i++) {
        if (a[i] == 2) d++;
    }
    cout << d;
    return 0;
}
