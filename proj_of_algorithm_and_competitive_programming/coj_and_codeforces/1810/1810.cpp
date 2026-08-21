#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n,b=0,a=0,l=0;
    cin >> n;
    deque<int>dq;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    while(!dq.empty()) {
        int k;
        if(dq.back()>dq.front()) {
            k=dq.back();
            dq.pop_back();
        }
        else {
            k=dq.front();
            dq.pop_front();
        }
        if(l%2==0) a+=k;
        else b+=k;
        l++;
    }
    cout << a << " " << b;
}
