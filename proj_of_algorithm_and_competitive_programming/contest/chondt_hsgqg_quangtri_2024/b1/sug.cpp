#include <bits/stdc++.h>
using namespace std;

const int mod1 = 1000000009, mod2 = 1000000003, maxn = 100005;
const int base = 311; // Nên dùng base >= 256 (như 311) để tránh đụng độ (collision) ASCII

string s;
int n, pre[maxn];
pair<long long, long long> hashing_arr[maxn], p[maxn], revhash[maxn];

// Lấy Hash xuôi
pair<long long, long long> get_hash1(int l, int r) {
    int len = r - l + 1;
    long long h1 = (hashing_arr[r].first - hashing_arr[l-1].first * p[len].first) % mod1;
    if (h1 < 0) h1 += mod1;
    
    long long h2 = (hashing_arr[r].second - hashing_arr[l-1].second * p[len].second) % mod2;
    if (h2 < 0) h2 += mod2;
    
    return {h1, h2};
}

// Lấy Hash ngược (chú ý công thức dùng r+1 vì xây dựng từ cuối mảng)
pair<long long, long long> get_hash2(int l, int r) {
    int len = r - l + 1;
    long long h1 = (revhash[l].first - revhash[r+1].first * p[len].first) % mod1;
    if (h1 < 0) h1 += mod1;
    
    long long h2 = (revhash[l].second - revhash[r+1].second * p[len].second) % mod2;
    if (h2 < 0) h2 += mod2;
    
    return {h1, h2};
}

bool check(int l, int r) {
    return get_hash1(l, r) == get_hash2(l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Tối ưu đọc ghi cho VNOJ (Chạy file INP nếu có, không thì đọc console)
    if (fopen("PADBLE.INP", "r")) {
        freopen("PADBLE.INP", "r", stdin);
        freopen("PADBLE.OUT", "w", stdout);
    }

    if (!(cin >> s)) return 0;
    n = s.size();

    // 1. Khởi tạo mảng lũy thừa p với base = 311
    p[0].first = p[0].second = 1;
    for(int i = 1; i <= n; ++i) {
        p[i].first = (p[i-1].first * base) % mod1;
        p[i].second = (p[i-1].second * base) % mod2;
    }

    // 2. Khởi tạo Hash xuôi và Prefix Sum
    hashing_arr[0].first = hashing_arr[0].second = 0;
    for(int i = 1; i <= n; ++i) {
        int c = s[i-1] - 'a';
        pre[i] = pre[i-1] + c;
        
        hashing_arr[i].first = (hashing_arr[i-1].first * base + s[i-1]) % mod1;
        hashing_arr[i].second = (hashing_arr[i-1].second * base + s[i-1]) % mod2;
    }

    // 3. Khởi tạo Hash ngược
    revhash[n+1].first = revhash[n+1].second = 0;
    for(int i = n; i >= 1; --i) {
        revhash[i].first = (revhash[i+1].first * base + s[i-1]) % mod1;
        revhash[i].second = (revhash[i+1].second * base + s[i-1]) % mod2;
    }

    int cnt = 0, ans = -1;
    
    // 4. Duyệt tìm xâu PADBLE
    for(int k = (n >> 1); k >= 1; --k) {
        int sz = (k << 1);
        cnt = 0;
        
        // Sửa i < n-sz+1 thành i <= n-sz+1
        for(int i = 1; i <= n - sz + 1; ++i) {
            int mid = i + k;
            int r = i + sz - 1;
            
            // Tối ưu: Đưa phần check điều kiện mảng pre lên trước hàm check Hash
            if(pre[r] - pre[i-1] != 0 && pre[r] - pre[i-1] != sz) {
                if(check(i, mid - 1) && check(mid, r)) {
                    ++cnt;
                }
            }
        }
        
        if(cnt > 0) {
            ans = sz;
            break;
        }
    }

    if(ans == -1) cout << ans;
    else cout << ans << ' ' << cnt;

    return 0;
}