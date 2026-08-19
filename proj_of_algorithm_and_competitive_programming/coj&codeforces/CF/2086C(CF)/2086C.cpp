#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n+1);
        for (int i = 1; i <= n; i++){
            cin >> p[i];
        }
        vector<int> d(n);
        for (int i = 0; i < n; i++){
            cin >> d[i];
        }

        vector<bool> removed(n+1, false);
        vector<bool> forced(n+1, false);

        int removedCount = 0, extra = 0;

        for (int i = 0; i < n; i++){
            int pos = d[i];
            removed[pos] = true;
            removedCount++;
            if(forced[pos]){
                forced[pos] = false;
                extra--;
            }
            int v = p[pos];
            if(v != pos && !removed[v] && !forced[v]){
                while(true){
                    if(removed[v] || forced[v]) break;
                    if(p[v] == v) break;
                    forced[v] = true;
                    extra++;
                    v = p[v];
                }
            }
            cout << removedCount + extra << (i < n-1 ? " " : "\n");
        }
    }
    return 0;
}
