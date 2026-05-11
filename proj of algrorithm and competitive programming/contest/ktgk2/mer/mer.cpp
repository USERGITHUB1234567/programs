#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    freopen("mer.inp", "r", stdin);
    freopen("mer.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    string a,b;
    string c;
    cin >> a >> b;
    int i=0;
    while(b!="") {
        bool ck=false;
        for(i; i<a.size(); i++) {
            c+=a[i];
            if(b[0]==a[i]) {
                c+=b[0];
                ck=true;
                //i++;
                break;
            }
        }
        if(!ck) c+=b[0];
        b.erase(0,1);
    }
    int kq=0;
    while(i<a.size()) {
        c+=a[i];
        i++;
    }
    //cout << c << "\n";
    for(int i=0; i<c.size()-1; i++) {
        if(c[i]!=c[i+1]) kq++;
    }
    cout << kq+1;
}
