#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    int k;
    cin >> s >> t >> k;
    int n = s.size(), m = t.size();
    vector<int> ans;

    for(int i = 0; i <= n - m; i++){
        int dc = 0, p1 = -1, p2 = -1;
        for(int j = 0; j < m; j++){
            if(s[i+j] != t[j]){
                dc++;
                if(dc == 1) p1 = j;
                else if(dc == 2) p2 = j;
                else break;
            }
        }
        if(dc == 2 && (p2 - p1 == k))
            ans.push_back(i+1);
    }

    cout << ans.size() << "\n";
    if(!ans.empty()){
        for(auto x : ans)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
