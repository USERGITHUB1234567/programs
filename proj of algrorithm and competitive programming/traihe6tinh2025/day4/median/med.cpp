#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define int long long
using namespace std;

const int maxn = 200005;
int h[maxn], n;
vector<int> a; // sẽ dùng với 1-indexing: phần tử thứ 0 dùng làm dummy

void solve() {
    if(n == 1) {
        cout << h[1];
        return;
    }
    else if(n % 2 == 0) {
        // Với n chẵn, theo đề bài, trung vị của tập đầy đủ (sắp xếp) có điều kiện:
        // (h[n/2] + h[n/2+1]) phải chẵn. Nếu không, in -1.
        if ((h[n/2] + h[n/2+1]) % 2 != 0) {
            cout << -1;
            return;
        }
        // In thứ tự bằng cách “interleaving” phần bên trái và bên phải.
        // Chạy vòng lặp từ i = n/2 xuống 1 (không dùng i=0 vì h[0] chưa được khởi tạo).
        for (int i = n/2; i >= 1; i--) {
            cout << h[i] << " " << h[n - i + 1] << " ";
        }
    }
    else {
        // Với n lẻ: giả sử n >= 3 (với n==1 đã xử lý)
        // Lấy 3 phần tử trung tâm trong mảng đã sắp xếp:
        // t1 = h[n/2], t2 = h[n/2+1], t3 = h[n/2+2]
        int t1 = h[n/2], t2 = h[n/2 + 1], t3 = h[n/2 + 2], mid;
        // Nếu không tồn tại cặp nào cho tổng chẵn thì không có phép interleaving nào hợp lệ.
        if ((t1 + t2) % 2 == 1 && (t1 + t3) % 2 == 1 && (t2 + t3) % 2 == 1) {
            cout << -1;
            return;
        }
        // Chọn chỉ số của phần tử trung vị theo cặp nào cho tổng chẵn
        if ((t1 + t2) % 2 == 0)
            mid = n/2 + 2;
        else if ((t1 + t3) % 2 == 0)
            mid = n/2 + 1;
        else if ((t2 + t3) % 2 == 0)
            mid = n/2;

        // Xây dựng vector a với chỉ số 1-indexed:
        a.clear();
        a.push_back(0); // dummy tại vị trí 0
        for (int i = 1; i <= n; i++) {
            if(i != mid)
                a.push_back(h[i]);
        }
        int new_n = n - 1; // số phần tử trong vector a (loại bỏ phần tử ở vị trí mid)
        // Interleaving các phần tử ở vector a:
        for (int i = new_n/2; i >= 1; i--) {
            cout << a[i] << " " << a[new_n - i + 1] << " ";
        }
        // Cuối cùng, in phần tử trung vị ban đầu:
        cout << h[mid];
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    sort(h + 1, h + n + 1);
    solve();
    return 0;
}
