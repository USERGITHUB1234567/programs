#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,h[200005],re[200005];
void soup()
{
    for(int i=1; i<=n; i++) {
        int ma=0,d=0;
        for(int j=i+1; j<=n; j++) {
            if(h[j]>ma) {
                ma=h[j];
                d++;
            }
        }
        re[i]=d;
    }
    for(int i=1; i<=n; i++) {
        cout << re[i];
        if(i<n) cout << " ";
    }
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> h[i];
    /*if(n<=2000) {
        soup();
        return 0;
    }*/
    priority_queue<int,vector<int>,greater<int>> pq;
    re[n]=0;
    pq.push(h[n]);
    for (int i=n-1; i>=1; i--) {
        int cnt=pq.size();
        while (!pq.empty() && pq.top()<=h[i]) {
            pq.pop();
        }
        pq.push(h[i]);
        re[i]=cnt;
    }
    for (int i = 1; i <= n; i++) {
        cout << re[i];
        if(i<n) cout << " ";
    }
}
