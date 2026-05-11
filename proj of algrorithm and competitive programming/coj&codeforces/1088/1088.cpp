#include <bits/stdc++.h>
using namespace std;
long long d;
void ch(int n, int a, int b)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(n == 0) return;
    if(b==a%3+1) {
        ch(n-1,a,6-a-b);
        cout << a << " " << b << "\n";
        d++;
        ch(n - 1,6 - a - b, b);
    }
    else {
        ch(n - 1, a, b);
        cout << a << " " << 6 - a - b << "\n";
        d++;
        ch(n - 1, b, a);
        cout << 6 - a - b << " " << b << "\n";
        d++;
        ch(n - 1, a, b);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, a, b;
    cin >> n >> a >> b;
    ch(n, a, b);
    cout << d;
}
