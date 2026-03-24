#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    if(n%k!=0) cout << n+k-(n%k);
    else cout << n+k;
}
