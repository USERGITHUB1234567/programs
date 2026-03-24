#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,a;
    cin >> s >> a;
    for(long long i=0; i<a.size(); i++) {
        bool check=false;
        for(long long j=0; j<s.size(); j++) {
            if(s[j]==a[i]) {
                check=true;
                s.erase(j,1);
                break;
            }
        }
        if(check==false) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << "POSSIBLE";
}
