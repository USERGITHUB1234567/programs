#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,s1,s2;
    cin >> s >> s1 >> s2;
    while(s.find(s1)!=-1) {
        long long p=s.find(s1);
        s.erase(p,s1.size());
        s.insert(p,s2);
    }
    cout << s;
}
