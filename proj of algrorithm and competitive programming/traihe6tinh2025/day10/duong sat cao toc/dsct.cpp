#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1000006;
long long h[maxn],pre[maxn],suf[maxn];
 
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> h[i];
        }
        pre[1] = h[1] + 1;
        for (int i = 2; i <= n; i++){
            pre[i] = max(pre[i - 1], h[i] + i);
        }
        suf[n] = h[n] - n;
        for (int i = n - 1; i >= 1; i--){
            suf[i] = max(suf[i + 1], h[i] - i);
        }
        long long kq = 0;
        for (int i = 1; i <= n; i++){
            long long l = pre[i] - i;
            long long r = suf[i] + i;
            long long H = max(l, r);
            kq += (H - h[i]);
        }
        cout << kq << "\n";
    }
    return 0;
}
