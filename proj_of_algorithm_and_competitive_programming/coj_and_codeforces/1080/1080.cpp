#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    cout << (max_element(a,a+n)-a)+1;
}
