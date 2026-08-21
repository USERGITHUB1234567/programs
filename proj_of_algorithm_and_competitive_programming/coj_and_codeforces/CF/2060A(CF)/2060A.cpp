#include <bits/stdc++.h>
using namespace std;

int cal(int a1, int a2, int a4, int a5) {
    int kq = 0;
    int a3_1 = a4 - a2;
    int a3_2 = a5 - a4;
    int a3_3 = a4 - a1;
    vector<int> a3_values = {a3_1, a3_2, a3_3};
    for (int a3 : a3_values) {
        int cnt = 0;
        if (a1 + a2 == a3) ++cnt;
        if (a2 + a3 == a4) ++cnt;
        if (a3 + a4 == a5) ++cnt;
        kq = max(kq, cnt);
    }

    return kq;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        cout << cal(a1, a2, a4, a5) << "\n";
    }
    return 0;
}
