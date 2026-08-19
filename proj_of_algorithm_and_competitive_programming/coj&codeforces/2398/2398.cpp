#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int m,n;
    cin >> m >> n;
    char a[m][n];
    int d=0;
    string t="acef";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) cin >> a[i][j];
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            string s="";
            s+=a[i][j];
            s+=a[i+1][j];
            s+=a[i][j+1];
            s+=a[i+1][j+1];
            sort(s.begin(),s.end());
            if(s==t) d++;
        }
    }
    cout << d;
}
