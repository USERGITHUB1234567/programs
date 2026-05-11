#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    long long kq = 0, f = -1;
    cin >> s;
    for (long long i = 0; i <= s.size() - 4; i++){
        if (s.substr(i, 4) == "bear") f = i;
        if (f != -1) kq += f + 1;
    }
    cout << kq;
    return 0;
}
