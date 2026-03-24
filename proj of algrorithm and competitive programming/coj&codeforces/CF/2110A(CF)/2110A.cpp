#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,k1=0,k2=0;
        cin >> n;
        deque<int>d1,d2;
        int a[n+1];
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1,a+1+n);
        for(int i=1; i<=n; i++) {
            int x=a[i];
            d1.push_back(x);
            d2.push_back(x);
        }
        while((d1.front()+d1.back())%2!=0 && !d1.empty()) {
            d1.pop_back();
            k1++;
        }
        while((d2.front()+d2.back())%2!=0 && !d2.empty()) {
            d2.pop_front();
            k2++;
        }
        cout << min(k1,k2) << "\n";
    }
}
