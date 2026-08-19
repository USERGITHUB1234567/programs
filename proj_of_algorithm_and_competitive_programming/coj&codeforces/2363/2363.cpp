#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long s, A, B;
    cin >> n >> m >> s >> A >> B;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int j = 0; j < m; j++){
        cin >> b[j];
    }

    // Sắp xếp giảm dần các giá trị
    sort(a.begin(), a.end(), greater<long long>());
    sort(b.begin(), b.end(), greater<long long>());

    // Tính tiền tố cho từng nhóm
    vector<long long> prefixA(n + 1, 0), prefixB(m + 1, 0);
    for (int i = 0; i < n; i++){
        prefixA[i + 1] = prefixA[i] + a[i];
    }
    for (int j = 0; j < m; j++){
        prefixB[j + 1] = prefixB[j] + b[j];
    }

    long long ans = 0;
    // Số đồ vật loại 1 tối đa có thể chọn sao cho không vượt s
    int maxA = min(n, (int)(s / A));
    for (int x = 0; x <= maxA; x++){
        long long weightUsed = x * A;
        long long remaining = s - weightUsed;
        int y = min(m, (int)(remaining / B));
        long long totalValue = prefixA[x] + prefixB[y];
        ans = max(ans, totalValue);
    }

    cout << ans << "\n";
    return 0;
}
