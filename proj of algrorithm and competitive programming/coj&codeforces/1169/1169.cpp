#include <bits/stdc++.h>
using namespace std;
void hamole(long long n)
{
    long long t = n;
    for (long long p=2; p*p<=n; p++) {
        if (n%p==0) {
            while (n%p==0) {
                n/=p;
            }
            t-=t/p;
        }
    }
    if (n > 1) {
        t-=t/n;
    }
    cout << t;
}
int main()
{
    long long n;
    cin >> n;
    hamole(n);
}
