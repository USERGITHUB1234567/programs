#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n,kt;
        cin >> n;
        vector<int> a(n);
        map<int,int>mp;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        int cd=-1;
        for(auto x:mp) {
            if(x.second>=2) {
                cd=x.first;
                kt=x.second-2;
            }
        }
        if(cd==-1) {
            cout << cd << "\n";
            continue;
        }
        int d=-1,ng=-1;
        int er=2;
        for(int i=0; i<a.size(); i++) {
            if(a[i]==cd and er>0) {
                a.erase(a.begin()+i);
                er--;
                i--;
            }
            if(er==0) break;
        }
        sort(a.begin(),a.end(),greater<int>());
        bool ck=false;
        for(int i=0; i<a.size()-1; i++) {
            int x=a[i],y=a[i+1];
            if(x<y) swap(x,y);
            if(y+2*cd>x) {
                ck=true;
                ng=y;
                d=x;
            }
        }
        if(!ck) {
            cout << -1 << "\n";
            continue;
        }
        //for(int i:a) cout << i << " ";
        //cout << "\n";
        cout << cd << " " << cd << " " << ng << " " << d << "\n";
    }
}
