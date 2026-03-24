#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,c,t=0,ma=0;
    cin >> n >> m >> c;
    long long a[n],b[m];
    bool ch[n];
    memset(ch,false,sizeof(ch));
    for(long long i=0; i<n; i++) cin >> a[i];
    for(long long i=0; i<m; i++) {
        cin >> b[i];
        if(ch[b[i]-1]==false) {
            t+=a[b[i]-1];
            ch[b[i]-1]=true;
        }
        else {
            t-=a[b[i]-1];
            ch[b[i]-1]=false;
        }
        if(t>m) {
            cout << "Fuse was blown.";
            return 0;
        }
        else ma=max(m,t);
    }
    cout << "Fuse was not blown." << "\n" << "Max power consumption was" << " " << ma << ' ' << "amperes.";
}
