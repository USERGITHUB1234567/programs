// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> int die(T x) { cout << x << endl; return 0; }

#define mod_fft 998244353
#define mod_nfft 1000000007
#define INF 100000000000000
#define LNF 1e15
#define LOL 12345678912345719ll

struct LL {

    static const ll m = mod_fft;
    long long int val;

    LL(ll v) {val=reduce(v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static long long int reduce(ll x, ll md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const ll& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const ll& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const ll& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const ll& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const ll& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const ll& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const ll& y){
        ll z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(ll y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const ll& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const ll& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }

int N;
vector<ll> segtree;

void pull(int t) {
    segtree[t] = max(segtree[2*t], segtree[2*t+1]);
}

void point_set(int idx, ll val, int L = 1, int R = N, int t = 1) {
    if (L == R)  segtree[t] = val;
    else {
        int M = (L + R) / 2;
        if (idx <= M) point_set(idx, val, L, M, 2*t);
        else point_set(idx, val, M+1, R, 2*t+1);
        pull(t);
    }
}

ll range_add(int left, int right, int L = 1, int R = N, int t = 1) {
    if (left <= L && R <= right) return segtree[t];
    else {
        int M = (L + R) / 2;
        ll ret = 0;
        if (left <= M) ret = max(ret, range_add(left, right, L, M, 2*t));
        if (right > M) ret = max(ret, range_add(left, right, M+1, R, 2*t+1));
        return ret;
    }
}

void build(vector<ll>& arr, int L = 1, int R = N, int t = 1) {
    if (L == R)  segtree[t] = arr[L-1];
    else {
        int M = (L + R) / 2;
        build(arr, L, M, 2*t);
        build(arr, M+1, R, 2*t+1);
        pull(t);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        int bad = -1, margin = 1e9, need = 0;
        bool reject = 0;
        for (int i = 0; i < N; i++) {
            cin >> B[i];
            if (A[i] < B[i]) {
                if (bad != -1) reject = 1;
                bad = i;
                need = B[i] - A[i];
            } else {
                margin = min(margin, A[i] - B[i]);
            }
        }
        if (reject) {
            cout << "NO" << endl;
            continue;
        } else {
            cout << ((margin >= need) ? "YES" : "NO") << endl;
        }
    }
}
