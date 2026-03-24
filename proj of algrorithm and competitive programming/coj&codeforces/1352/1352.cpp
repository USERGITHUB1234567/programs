#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int>st;
    for(long long i=1; i<=n; i++) {
        int a;
        cin >> a;
        while(st.size()>=2) {
            int a1=st.top();
            st.pop();
            int a2=st.top();
            st.pop();
            if(a1<a2 and a1<a) st.push(a2);
            else {
                st.push(a2);
                st.push(a1);
                break;
            }
        }
        st.push(a);
    }
    cout << st.size();
}
