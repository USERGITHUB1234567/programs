#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
string s;
bool pa(string s)
{
    int i=0;
    while(i<s.size()/2) {
        if(s[i]!=s[s.size()-i-1]) return false;
        i++;
    }
    return true;
}
int main()
{
    cin >> n >> s;
    int d=0;
    for(int i=(n/2)-1; i>=0; i--) {
        if(s[i]!=s[n-i-1]) {
            //cout << 2*(i+1);
            //return 0;
            d++;
        }
    }
    int kq=2*d;
    if(n%2==0) kq--;
    cout << kq;
}
