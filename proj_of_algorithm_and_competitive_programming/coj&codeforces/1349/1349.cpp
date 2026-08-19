#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long a[n],b[n];
    for(long long i=0; i<n; i++) {
        cin >> a[i];
        b[i]=i+1;
    }
    stack<long long>st;
    long long vt=1;
    for(long long i=0; i<n; i++) {
        for(vt; vt<=a[i]; vt++) st.push(vt);
        if(st.top()==a[i]) st.pop();
        else {
            cout << "No";
            return 0;
        }
    }
    cout <<  "Yes";
}
