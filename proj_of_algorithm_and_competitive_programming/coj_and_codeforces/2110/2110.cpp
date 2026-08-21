#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long ft[100005],n,m;
void update(int i,int v)
{
    while(i<=n) {
        ft[i]+=v;
        i+=(i&-i);
    }
}
long long su(int i)
{
    long long s=0;
    while(i>0) {
        s+=ft[i];
        i-=(i&-i);
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    while(m--) {
        char c;
        cin >> c;
        long long i,j;
        cin >> i >> j;
        if(c=='+') {
            update(i,j);
        }
        else cout << su(j)-su(i-1) << "\n";
    }
    return 0;
}
