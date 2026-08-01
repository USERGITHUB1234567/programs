#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("test01.in", "r", stdin);
    //freopen("", "w", stdout);
    /*
    Thuật toán 1:
    + Chia bảng thành lưới ô vuông đơn vị
    + Mỗi ô vuông kiểm tra xem có bao nhiêu tấm áp phích phủ lên đó
        => câu trả lời bài toán
    + DPT O(w.h.n)
    Thuật toán 2:
    + Chia bảng thành các hình chữ nhật bởi các đường ngang, dọc của các tấm áp phích
    + Xét mỗi hình chữ nhật đó xem có bao nhiêu tấm áp phích phủ lên
    + DPT O(n^3)
    */

    int n, w, h, xl[101], yl[101], xh[101], yh[101];
    int nx, ny, x[203], y[203], areal = 0, dmax = 0, area2 = 0;
    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++) {
        cin >> xl[i] >> yl[i] >> xh[i] >> yh[i];
        x[i] = xl[i];
        x[n + i] = xh[i];
        y[i] = yl[i];
        y[n + i] = yh[i];
    }
    x[2 * n + 1] = 0;
    x[2 * n + 2] = w;
    y[2 * n + 1] = 0;
    y[2 * n + 2] = h;
    nx = 2 * n + 2;
    ny = 2 * n + 2;
    sort(x + 1, x + 1 + nx);
    nx = unique(x + 1, x + 1 + nx) - x - 1;
    sort(y + 1, y + 1 + ny);
    ny = unique(y + 1, y + 1 + ny) - y - 1;
    for (int i = 2; i <= nx; i++) {
        for (int j = 2; j <= ny; j++) { // hcn (x[i - 1], y[j - 1]) & (x[i], y[j])
            int d = 0; // đếm số hcn ban đầu phủ lên hcn trên
            for (int k = 1; k <= n; k++)
                if (xl[k] <= x[i - 1] && x[i] <= xh[k] && yl[k] <= y[j - 1] && y[j] <= yh[k])
                    d++;
            int s = (x[i] - x[i - 1]) * (y[j] - y[j - 1]);
            if (d == 0) areal += s;
            else
                if (d == dmax) area2 += s;
                else
                    if (d > dmax) {
                        dmax = d;
                        area2 = s;
                    }
        }
    }
    cout << areal << " " << dmax << " " << area2 << "\n";
    return 0;
}
