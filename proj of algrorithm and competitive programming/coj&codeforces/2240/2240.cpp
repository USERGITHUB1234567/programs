#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int k=0,re=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='(') k++;
        else k--;
        re=min(k,re);
    }
    cout << -re;
}
