#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#define file(name) freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long r1, p1, s1;
        long long r2, p2, s2;
        cin >> r1 >> p1 >> s1 >> r2 >> p2 >> s2;
        long long n = r1 + p1 + s1;
        long long ans1 = 0;
        long long t;
        t = min(r1, s2);
        ans1 += t;
        long long rr1 = r1 - t;
        long long ss2 = s2 - t;
        t = min(p1, r2);
        ans1 += t;
        long long pp1 = p1 - t;
        long long rr2 = r2 - t;
        t = min(s1, p2);
        ans1 += t;
        long long ss1 = s1 - t;
        long long pp2 = p2 - t;
        long long ans3 = 0;
        ans3 += min(rr1, rr2);
        ans3 += min(pp1, pp2);
        ans3 += min(ss1, ss2);
        long long maxx = 2 * ans1 + ans3;
        long long ans2 = 0;
        t = min(r1, p2);
        ans2 += t;
        rr1 = r1 - t;
        pp2 = p2 - t;
        t = min(p1, s2);
        ans2 += t;
        pp1 = p1 - t;
        ss2 = s2 - t;
        t = min(s1, r2);
        ans2 += t;
        ss1 = s1 - t;
        rr2 = r2 - t;
        long long res = 0;
        res += min(rr1, rr2);
        res += min(pp1, pp2);
        res += min(ss1, ss2);
        long long minn = 2 * n - 2 * ans2 - res;
        cout << maxx << " " << minn << "\n";
    }
    return 0;
}