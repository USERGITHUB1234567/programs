#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long cnt=1;
    sort(s.begin(),s.end());

    while(next_permutation(s.begin(),s.end())) {
        cnt++;
    }
    cout << cnt << "\n";
    cout << s << "\n";
    while(next_permutation(s.begin(),s.end())) {
        cout << s << "\n";
    }
    return 0;
}
