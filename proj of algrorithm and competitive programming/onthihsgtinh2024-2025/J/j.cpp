#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    long long t=0;
    while(n--) {
        char c;
        cin >> c;
        long long a;
        cin >> a;
        if(c=='P') t+=a;
        else {
            if(a<=t) {
                cout << "NO";
            }
            else cout << "YES";
            t-=a;
            if(t<0) t=0;
            cout << "\n";
        }
    }
}
