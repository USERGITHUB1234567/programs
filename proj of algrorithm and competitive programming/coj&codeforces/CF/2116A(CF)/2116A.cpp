#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int g=min(a,c),f=min(b,d);
        if(g>=f) cout << "Gellyfish\n";
        else cout << "Flower\n";
    }
}
