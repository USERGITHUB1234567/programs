#include <bits/stdc++.h>
using namespace std;
long long d=0;
string s;
void ch(int n, int a, int b)
{
    if(n==0) return;
    if(s[n-1]=='x' and b==a%3+1 or s[n-1]=='n' and a==b%3+1 or s[n-1]=='t' and abs(a-b)==1 or s[n-1]=='h') {
        ch(n-1,a,6-a-b);
        cout << a << " " << b << "\n";
        d++;
        ch(n-1,6-a-b,b);
    }
    else {
        ch(n-1,a,b);
        cout << a << " " << 6-a-b << "\n";
        d++;
        ch(n-1,b,a);
        cout << 6-a-b << " " << b << "\n";
        d++;
        ch(n-1,a,b);
    }
}
int main()
{
    long long a,b;
    cin >> a >> b;
    cin >> s;
    long long n=s.size();
    ch(n,a,b);
    cout << d;
}
