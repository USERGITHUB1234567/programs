/**/ 
#pragma GCC optimize("O3","Ofast","unroll-loops") 
#include <bits/stdc++.h> 
#define file(name) freopen(name ".inp", "r", stdin); freopen(name ".out", "w", stdout); 
#define all(x) x.begin(), x.end() 
#define sortunique(x) sort(all(x)); x.erase(unique(all(x)), x.end()); 
#define forw(i,a,b) for(int (i)=(a); (i)<=(b); ++(i)) 
#define forb(i,a,b) for(int (i)=(a); (i)>=(b); --(i)) 
#define eb emplace_back 
#define fi first 
#define se second 
#define pb push_back 
using namespace std; 
using namespace std::chrono; 
static const int maxd=1003; 
typedef short bignum[maxd]; 
typedef long long ll; 
typedef long double ld; 
const int maxn=200005,mod=1000000007,maxb=320; 
namespace utilities{ 
    long long fact[maxn],ifact[maxn]; 
    long long __uiagcd(long long a, long long b) { if(a<b) swap(a,b); while(a%b!=0) {long long c=a%b;a=b,b=c;} return b; } 
    inline ll __logarit(ll k, ll n){ll res=0;while(n>0){n/=k;++res;}return res;} 
    inline ll modexp(ll b, ll e, ll m) { ll res=1%m; while(e>0) { if(e&1) res=(res*b)%m; b=(b*b)%m; e>>=1; } return res; } 
    void setUpFactor() { fact[0]=1; for(int i=1; i<maxn; ++i) fact[i]=fact[i-1]*i%mod; int tc=maxn-1; ifact[tc]=modexp(fact[tc],mod-2,mod); for(int i=tc; i>=1; --i) ifact[i-1]=ifact[i]*i%mod; } 
    inline long long ncr(long long k, long long n) {return (k==n?1:fact[n]*ifact[n-k]%mod*ifact[k]%mod);} 
    inline int lomuto_partition(vector<int>&a, int l, int r) {int pivot=a[r],i=l-1;for(int j=l; j<r; ++j) {if(a[j]<=pivot) {++i;swap(a[i],a[j]);}}swap(a[r],a[i+1]);return i+1;} 
    inline int hoare_partition(vector<int>&a, int l, int r) {int pivot=a[l],i=l,j=r;bool partition=true;while(partition) {while(a[i]<pivot) ++i;while(a[j]>pivot) --j;if(i<j) {swap(a[i],a[j]);++i,--j;}else partition=false;}return j;} 
    inline void quicksort_lomuto(vector<int>&a, int l, int r) {if(l>=r) return;int p=lomuto_partition(a,l,r);quicksort_lomuto(a,l,p-1);quicksort_lomuto(a,p+1,r);} 
    inline void quicksort_hoare(vector<int>&a, int l, int r) {if(l>=r) return;int p=hoare_partition(a,l,r);quicksort_hoare(a,l,p);quicksort_hoare(a,p+1,r);} 
} 
//using namespace utilities; 
mt19937_64 generator1(steady_clock::now().time_since_epoch().count()); 
mt19937_64 generator2(high_resolution_clock::now().time_since_epoch().count()); 
inline long long rnd1(long long a, long long b) {return a+generator1()%(b-a+1);} 
inline long long rnd2(long long a, long long b) {return a+generator2()%(b-a+1);} 
auto imp_st=high_resolution_clock::now(); 
inline void start_timer() {imp_st=high_resolution_clock::now();} 
inline void get_execution_time() { auto imp_en=high_resolution_clock::now(); cerr << "Implementation Time: "<< duration_cast<milliseconds>(imp_en-imp_st).count() << " ms\n"; } 
int n,a[maxn],b[maxn];
map<int,int>cnt;
int main(int argc, char** argv) { 
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr); 
    if (!(cin >> n)) return 0;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];

    vector<int> vals;
    vals.reserve(4 * n);
    vals.push_back(a[1]);
    for(int i=2; i<=n; ++i) {
        vals.push_back(a[i]);
        vals.push_back(b[i]);
    }
    
    if (n >= 2) {
        // Tạo mảng prefix max bắt đầu tính từ vị trí thứ 2
        vector<int> A_prime(n-1), B_prime(n-1);
        A_prime[0] = a[2];
        for(int i=3; i<=n; ++i) A_prime[i-2] = max(A_prime[i-3], a[i]);
        B_prime[0] = b[2];
        for(int i=3; i<=n; ++i) B_prime[i-2] = max(B_prime[i-3], b[i]);

        for(int x : A_prime) vals.push_back(x);
        for(int x : B_prime) vals.push_back(x);

        // Chuẩn hóa lấy các giá trị duy nhất (Rời rạc hóa)
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int K = vals.size();
        vector<long long> freq(K, 0);

        auto get_id = [&](int x) {
            return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        };

        // Đếm ở viền (Hàng 1 và Cột 1)
        freq[get_id(a[1])]++;
        for(int i=2; i<=n; ++i) {
            freq[get_id(a[i])]++;
            freq[get_id(b[i])]++;
        }

        long long prev_cnt = 0;
        int ptrA = 0, ptrB = 0;
        
        // Đếm theo sub-grid bằng hai con trỏ (hai mảng A_prime, B_prime đều đã tăng dần)
        for(int i=0; i<K; ++i) {
            int v = vals[i];
            while(ptrA < n - 1 && A_prime[ptrA] <= v) ptrA++;
            while(ptrB < n - 1 && B_prime[ptrB] <= v) ptrB++;
            long long current_cnt = 1LL * ptrA * ptrB;
            freq[i] += (current_cnt - prev_cnt);
            prev_cnt = current_cnt;
        }

        long long max_f = -1;
        int best_val = -1;
        
        // Lấy loại Virut xuất hiện nhiều nhất, ưu tiên chỉ số (loại) lớn hơn
        for(int i=0; i<K; ++i) {
            if (freq[i] >= max_f) {
                max_f = freq[i];
                best_val = vals[i];
            }
        }
        cout << best_val << " " << max_f << "\n";
    } else {
        cout << a[1] << " 1\n";
    }
    return 0; 
} 
/**/