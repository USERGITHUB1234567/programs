#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n,x,k,lu=-1,lu2=-1;
        cin >> n >> x >> k;
        string s;
        cin >> s;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='L') x--;
            else x++;
            if(x==0) {
                lu=i+1;
                break;

            }
        }
        if(lu==-1) {
            cout << 0 << "\n";
            continue;
        }
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='L') x--;
            else x++;
            if(x==0) {
                lu2=i+1;
                break;
            }
        }
        if(k<lu) {
            cout << 0 << "\n";
            continue;
        }
        k-=lu;
        long long kq=1;
        if(lu2!=-1) kq+=k/lu2;
        cout << kq << "\n";
    }
}

