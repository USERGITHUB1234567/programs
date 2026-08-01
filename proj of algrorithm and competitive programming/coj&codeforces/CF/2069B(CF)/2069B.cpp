#include <bits/stdc++.h>
#define ford(a,b,c) for(int a=b;a<=c;a++)
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout);
#define siz size()
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n, vector<int>(m));
        int x = n * m;
        vector<int> gia(x+1, 0);
        vector<bool> cur(x+1, false);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> g[i][j];
                int c = g[i][j];
                cur[c] = true;
                if(gia[c] == 0)
                    gia[c] = 1;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int c = g[i][j];
                if(j + 1 < m && g[i][j+1] == c)
                    gia[c] = 2;
                if(i + 1 < n && g[i+1][j] == c)
                    gia[c] = 2;
            }
        }

        long long sn = 0;
        int mx = 0;
        for (int c = 1; c <= x; c++){
            if(cur[c]){
                sn += gia[c];
                mx = max(mx, gia[c]);
            }
        }

        long long ans = sn - mx;
        cout << ans << "\n";
    }
    return 0;
}
