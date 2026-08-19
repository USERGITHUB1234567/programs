#include <bits/stdc++.h>
using namespace std;
void chuyen(int n,int a,int b)
{
    if(n==0) return;
    chuyen(n-1,a,6-a-b);
    cout << a << " " << b << "\n";
    chuyen(n-1,6-a-b,b);
}
int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    cout << pow(2,n)-1 << endl;
    chuyen(n,a,b);
    return 0;
}
