#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int d[n+1],h[n+1];
        pair<int,int>p[n+1];
        queue<int>q;
        for(int i=1; i<=n; i++) cin >> d[i];
        for(int i=1; i<=n; i++) cin >> p[i].first >> p[i].second;
        int ch=0;
        bool ck=true;
        for(int i=1; i<=n; i++) {
            if(d[i]==-1) q.push(i);
            if(d[i]==1) ch++;
            int x=p[i].second-ch;
            while(q.size()>x && ck) q.pop();
            while(ch<p[i].first && !q.empty()) {
                ch++;
                d[q.front()]=1;
                q.pop();
            }
            if(ch<p[i].first || ch>p[i].second) {
                ck=false;
                break;
            }
        }
        if(!ck) {
            cout << -1 << "\n";
            continue;
        }
        else {
            for(int i=1; i<=n; i++) {
                if(d[i]==-1) cout << 0 << " ";
                else cout << d[i] << " ";
            }
        }
        cout << "\n";
    }
}
