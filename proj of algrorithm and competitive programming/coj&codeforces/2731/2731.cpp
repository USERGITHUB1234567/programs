#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long a,b,c;
        cin >> a >> b >> c;
        int k=b-c;
        if(k<1) k=k*-1*2;
        a--;
        if(k>a) cout << 1 << "\n";
        else if(k<a) cout << 2 << "\n";
        else cout << 3 << "\n";
    }
}
