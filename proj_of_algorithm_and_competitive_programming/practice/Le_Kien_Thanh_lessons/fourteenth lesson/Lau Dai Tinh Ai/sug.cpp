// Tính left_req, right_req từ trước mất O(N)...

vector<int> p(n);
iota(p.begin(), p.end(), 1); // 1, 2, ..., n
mt19937 rng(1337);           // Khởi tạo Random Generator
shuffle(p.begin(), p.end(), rng); // Xáo trộn ngẫu nhiên

vector<bool> done(n + 1, false);
vector<int> L(n + 1), R(n + 1);
for (int i = 1; i <= n; ++i) { L[i] = i; R[i] = i; }

for (int i : p) {
    int l = i, r = i;
    while (true) {
        bool changed = false;
        
        // Cố gắng nở sang trái
        if (l > 1 && r >= right_req[l - 1]) { // Đủ chìa mở cửa l-1
            l--;
            if (done[l]) { // "Nổ hũ", nuốt luôn thằng đã tính
                r = max(r, R[l]);
                l = L[l];
            }
            changed = true;
        }
        
        // Cố gắng nở sang phải
        if (r < n && l <= left_req[r]) { // Đủ chìa mở cửa r
            r++;
            if (done[r]) { // "Nổ hũ"
                l = min(l, L[r]);
                r = max(r, R[r]);
            }
            changed = true;
        }
        
        if (!changed) break;
    }
    L[i] = l;
    R[i] = r;
    done[i] = true;
}