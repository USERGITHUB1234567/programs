#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;
const int maxn=1000006;
int to[maxn],l,d,kq=0;
void cal()
{
    to[0]=to[1]=0;
    for(int i=1; i<maxn; i++) {
        int j=i+i;
        while(j<maxn) {
            to[j]+=i;
            j+=i;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cal();
    cin >> l >> d;
    for(int i=1; i<l; i++) {
        if(abs(to[i]-i)<=d) kq++;
    }
    cout << kq;
}
