#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,k,p;
        cin >> n >> k >> p;
        k=abs(k);
        p=abs(p);
        if(p*n<k) {
            cout << -1 << "\n";
        }
        else {
            int h=k/p;
            if(k%p!=0) h++;
            cout << h << "\n";
        }
    }
}
