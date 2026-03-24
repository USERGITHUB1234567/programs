#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int l[200001],r[200001];
int main()
{
    int n, m, kq = 0;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for (int i = 0,j=0; j < m; j++,i++) {
        while(s[i]!=t[j]) i++;
        l[j]=i;
    }
    for(int i=n-1, j=m-1; j>=0; j--,i--) {
        while(s[i]!=t[j]) i--;
        r[j]=i;
    }
    for(int i=1; i<m; i++) {
        kq=max(kq,abs(r[i]-l[i-1]));
    }
    cout << kq;
}
