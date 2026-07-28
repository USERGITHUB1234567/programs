#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 36;
const ll INF = 1e18 + 36;
const long double EPS = 1e-15;
const int N = 1e5;
int minmize(int a, int b) {
    return a < b ? a : b;
}
int maxmize(int a, int b) {
    return a > b ? a : b;
}
ll Minmize(ll a, ll b) {
    return a < b ? a : b;
}
ll Maxmize(ll a, ll b) {
    return a > b ? a : b;
}
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //file("DHKA");
    cin >> s;
    int n = s.size();
    string t = s + s;
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n) {
        if (t[i + k] == t[j + k])
            ++k;
        else if (t[i + k] > t[j + k]) {
            i += k + 1;
            if (i <= j)
                i = j + 1;
            k = 0;
        } else {
            j += k + 1;
            if (j <= i)
                j = i + 1;
            k = 0;
        }
    }
    int st = minmize(i, j);
    for (int o = 0; o < n; ++o)
        cout << t[st + o];
    return 0;
}