#include <bits/stdc++.h>
using namespace std;
int gm(const vector<int>& a, int n){
    vector<int> fr(n+2,0);
    for(int v : a){
        if(v <= n+1) fr[v]++;
    }
    for(int i = 0; i < fr.size(); i++){
        if(fr[i] == 0) return i;
    }
    return n+1;
}
bool cp(const vector<int>& a, int n, int k, int x){
    if(x == 0) return true;
    int sc = 0;
    vector<bool> sv(x, false);
    int fd = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < x && !sv[a[i]]){
            sv[a[i]] = true;
            fd++;
        }
        if(fd == x){
            sc++;
            if(sc >= k) return true;
            fill(sv.begin(), sv.end(), false);
            fd = 0;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int mc = gm(a, n);
        int lo = 0, hi = mc, an = 0;
        while(lo <= hi){
            int md = (lo + hi) / 2;
            if(cp(a, n, k, md)){
                an = md;
                lo = md + 1;
            }
            else hi = md - 1;
        }
        cout << an << "\n";
    }
    return 0;
}
