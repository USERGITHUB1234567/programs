#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> results;

void generate(int left, int right, string &current) {
    if (left > right) {
        if (n == 1 || current[0] != '0') { // Bỏ qua số bắt đầu bằng 0 khi n > 1
            results.push_back(current);
        }
        return;
    }

    if (left == right) { // Vị trí trung tâm (chỉ áp dụng khi n lẻ)
        for (char ch : {'0', '1', '8'}) {
            current[left] = ch;
            results.push_back(current);
        }
        return;
    }

    // Sinh các cặp đối xứng
    for (auto &p : vector<pair<char, char>>{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}}) {
        if (left == 0 && p.first == '0') continue; // Bỏ qua số bắt đầu bằng '0' khi n > 1
        current[left] = p.first;
        current[right] = p.second;
        generate(left + 1, right - 1, current);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    string current(n, ' ');
    generate(0, n - 1, current);

    sort(results.begin(), results.end());
    for (const string &num : results) {
        cout << num << "\n";
    }
    return 0;
}
