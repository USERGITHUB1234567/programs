#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mmb(x, v) memset(x, v, sizeof(x))
#define FOR(i, x, y) for (int i = (int) x; i <= (int) y; ++i)
#define REP(i, x, y) for (int i = (int) x; i >= (int) y; --i)
#define all(x) x.begin(), x.end()
#define zip(x) sort(x.begin(), x.end()); x.erase(unique(all(x)), x.end());
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 36;
const ll INF = 1e18 + 36;
const long double EPS = 1e-15;
const int N = 1e5 + 15;
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

int n, cnt, k;
string S;
vector<bool> removed;
namespace personA{string send(string w);}
namespace personB{void play(string s);}
void take(int p) {
   if (p < 0 || p >= n) {
       cout << "Invalid take: " << p << '\n';
       return;
   }
   if (removed[p]) {
       cout << "Coin already removed: " << p << '\n';
       return;
   }
   if (S[p] != '0') {
       cout << "Take wrong coin: " << p << '\n';
       ++k;
       return;
   }
   removed[p] = true;
   ++cnt;
   int l = p - 1;
   while (l >= 0 && removed[l])
       --l;
   int r = p + 1;
   while (r < n && removed[r])
       ++r;
   if (l >= 0)
       S[l] = (S[l] == '0' ? '1' : '0');
   if (r < n)
       S[r] = (S[r] == '0' ? '1' : '0');
   cout << "take(" << p << ")\n";
}

int main() {
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   srand(chrono::steady_clock().now().time_since_epoch().count());
   n = 50;
   S.clear();
   FOR(i, 0, n - 1) {
       if (i && S.back() == '0')
           S.push_back('1');
       else
           S.push_back(char('0' + (rand() & 1)));
   }
   removed.assign(n, false);
   cout << "n = " << n << '\n';
   cout << "Initial: " << S << "\n\n";
   string msg = personA::send(S);
   personB::play(msg);
   cout << "\nFinal:\n";
   FOR(i, 0, n - 1) {
       if (removed[i])
           cout << 'X';
       else
           cout << S[i];
   }
   cout << "\n TAKE = " << cnt;
   cout << '\n';
   cout << "NGU = " << k;
   return 0;
}