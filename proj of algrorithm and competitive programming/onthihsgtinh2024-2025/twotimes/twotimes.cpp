#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    freopen("twotimes", "r", stdin);
    freopen("twotimes", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<vector<int>> b(n, vector<int>(51, 0));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i][a[i]]++;
        if (i > 0) {
            for (int j = 0; j < 51; j++) {
                b[i][j] += b[i-1][j];
            }
        }
    }
    while(q--) {
        int kq=0;
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        for(int i = 0; i < 51; i++) {
            int cnt = b[r][i] - (l > 0 ? b[l-1][i] : 0);
            if(cnt == 2) kq++;
        }
        cout << kq << "\n";
    }
    return 0;
}
