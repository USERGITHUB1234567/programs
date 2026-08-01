#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long a,b;
        cin >> a >> b;
        long long t=a+b;
        if(t%2==0) cout << "Bob\n";
        else cout << "Alice\n";
    }
}
