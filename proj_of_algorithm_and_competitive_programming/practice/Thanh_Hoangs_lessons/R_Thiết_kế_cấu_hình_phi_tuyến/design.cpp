#include <bits/stdc++.h>
using namespace std;
pair<int,int>p[5]={{1,1},{1,2},{1,3},{2,2},{2,3}};
long long a[5][21];
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;cin >> tc;
    for(int i=1; i<=3; ++i) a[i][0]=1;
    for(int i=1; i<=3; ++i) for(int j=1; j<=20; ++j) a[i][j]=a[i][j-1]*i;
    while(tc--) {
        int n,k;cin >> n >> k;
        for(int i=1; i<=k; ++i) {
            auto[x,y]=p[i-1];
            long long z=a[x][n]+a[y][n];
            cout << x*z << ' ' << y*z << ' ' << z << '\n';
        }
    }
    return 0;
}