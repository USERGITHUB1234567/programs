#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<pair<int, int>> ops;
    for(int i = 1; i <= n; i++){
        if(a[i] != i){
            int j = pos[i];
            swap(a[i], a[j]);
            ops.push_back({i, j});
            pos[a[i]] = i;
            pos[a[j]] = j;
        }
    }
    cout << ops.size() << "\n";
    for(auto &op : ops){
        cout << op.first << " " << op.second << "\n";
    }
    return 0;
}
