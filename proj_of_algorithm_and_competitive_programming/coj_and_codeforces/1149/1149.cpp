#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int m, x[55] = {0};
void dfs(int t, int vt, int max_value) {
    if (t == 0) {
        cout << m << " = ";
        for (int i = 1; i < vt; i++) {
            cout << x[i];
            if (i < vt - 1) cout << " + ";
        }
        cout << "\n";
        return;
    }
    for (int i = max_value; i >= 1; i--) {
        if (t - i >= 0) {
            x[vt] = i;
            dfs(t - i, vt + 1, i);
            x[vt] = 0;
        }
    }
}

int main() {
    cin >> m;
    dfs(m, 1, m);
    return 0;
}
/*#include <iostream>
#include <vector>
using namespace std;

void partition(int number, int max_value, vector<int>& current_partition) {
    // Nếu number == 0, in ra một cách phân tích
    if (number == 0) {
        cout << current_partition[0];
        for (size_t i = 1; i < current_partition.size(); i++) {
            cout << " + " << current_partition[i];
        }
        cout << endl;
        return;
    }

    // Thử các số hạng theo thứ tự giảm dần
    for (int i = min(number, max_value); i >= 1; i--) {
        current_partition.push_back(i); // Thêm số hạng vào dãy hiện tại
        partition(number - i, i, current_partition); // Gọi đệ quy với phần còn lại
        current_partition.pop_back(); // Loại bỏ số hạng vừa thêm để thử số tiếp theo
    }
}

int main() {
    int m;
    cin >> m;

    vector<int> current_partition;
    partition(m, m, current_partition);

    return 0;
}*/
