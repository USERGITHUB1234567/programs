#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    string s1,s2;
    cin >> s1 >> s2;
    int n=s1.size(), m=s2.size();
    int i=0, j=0;
    while (i<n && j<m) {
        if (s1.compare(i,n-i,s2,j,m-j)>0)
            cout << s1[i++];
        else
            cout << s2[j++];
    }
    while (i<n)
        cout << s1[i++];
    while (j<m)
        cout << s2[j++];
    return 0;
}
