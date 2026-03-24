#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    int n;
    string a,b;
    cin >> n >> a >> b;
    int kq=0;
    for(int i=0; i<n; i++) {
        if(a[i]==b[i+1] and a[i+1]==b[i] and a[i]!=a[i+1]) {
            swap(a[i],a[i+1]);
            kq++;
        }
    }
    for(int i=0; i<n; i++) {
        if(a[i]!=b[i]) {
            a[i]=b[i];
            kq++;
        }
    }

    cout << kq;
    return 0;
}
