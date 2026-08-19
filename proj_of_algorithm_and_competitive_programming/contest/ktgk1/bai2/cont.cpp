#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cont.inp", "r", stdin);
    freopen("cont.out", "w", stdout);
    int n,k;
    cin >> n >> k;
    deque<int>dq;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    bool c=true;
    while(c==true) {
        if(dq.size()==0) break;
        if(dq.front()<=k) dq.pop_front();
        else {
           if(dq.back()<=k) dq.pop_back();
           else c=false;
        }
    }
    cout << n-dq.size();
}
