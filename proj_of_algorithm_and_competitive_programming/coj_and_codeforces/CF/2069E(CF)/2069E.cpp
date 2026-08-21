#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int a,b,ab,ba; cin >> a >> b >> ab >> ba;
        int n = s.size();
        int ca = 0, cb = 0;
        for(char c : s){
            if(c=='A') ca++; else cb++;
        }
        int m0 = max({ca - a, cb - b, 0});
        int mm = 0, S = 0, SA = 0, SB = 0, F = 0;
        for (int i = 0; i < n; ){
            int j = i;
            while(j+1 < n && s[j] != s[j+1]) j++;
            int ln = j - i + 1;
            if(ln >= 2){
                int sm = ln / 2;
                mm += sm;
                if(ln == 2){
                    S++;
                    if(s[i]=='A') SA++; else SB++;
                } else {
                    F += sm;
                }
            }
            i = j + 1;
        }
        if(m0 > mm || m0 > (ab + ba)){
            cout << "NO\n";
            continue;
        }
        int m = m0;
        int L = max(0, m - F), U = min(m, S);
        bool po = false;
        for (int k = L; k <= U; k++){
            int l1 = (k <= SB ? 0 : k - SB);
            int h1 = min(k, SA);
            int l2 = l1, h2 = h1 + (m - k);
            int l3 = max(0, m - ba), h3 = ab;
            int lo = max(l2, l3), hi = min(h2, h3);
            if(lo <= hi){ po = true; break; }
        }
        cout << (po ? "YES" : "NO") << "\n";
    }
    return 0;
}
