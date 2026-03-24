#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n,k,kq=0;
        cin >> n >> k;
        if(n%2==1) {
            if(k%2==1) {
                n-=k;
                kq++;
                kq+=n/(k-1);
                if(n%(k-1)!=0) kq++;
            }
            else {
                n-=(k-1);
                kq++;
                kq+=n/k;
                if(n%k!=0) kq++;
            }
        }
        else {
            if(k%2==0) {
                kq+=n/k;
                if(n%k!=0) kq++;
            }
            else {
                kq+=n/(k-1);
                if(n%(k-1)!=0) kq++;
            }
        }
        cout << kq << "\n";
    }
}
