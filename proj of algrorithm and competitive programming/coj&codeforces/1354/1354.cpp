#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,vt;
    cin >> n;
    vt=n;
    stack<long long>st;
    long long a[n+1]={0};
    a[n]=0;
    while(n--) {
        char c;
        cin >> c;
        if(c=='+') {
            long long x;
            cin >> x;
            st.push(x);
            a[vt-1]=a[vt]+x;
            vt--;
        }
        if(c=='-') {
            cout << st.top() << "\n";
            st.pop();
            a[vt]=0;
            vt++;
        }
        if(c=='?') {
            long long k;
            cin >> k;
            cout << a[vt]-a[vt+k] << "\n";
        }
    }
}
