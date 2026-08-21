#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long a,b,k;
        cin >> a >> b >> k;
        long long h=a-b;
        long long t=k/2;
        long long kq=h*t;
        if(k%2==1) kq+=a;
        cout << kq << "\n";
    }
}
