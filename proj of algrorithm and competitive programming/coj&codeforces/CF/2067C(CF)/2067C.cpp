#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
bool ck(long long n)
{
    string s=to_string(n);
    for(int i=0; i<s.size(); i++) {
        if(s[i]=='7') return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long a[9]={9,99,999,9999,99999,999999,9999999,99999999,999999999};
        int kq=1e8;
        for(int i=0; i<9; i++) {
            int d=0;
            long long co=n;
            while(!ck(co)) {
                d++;
                co+=a[i];
            }
            kq=min(kq,d);
        }
        cout << kq << "\n";
    }
    return 0;
}
