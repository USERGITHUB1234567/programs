#include <bits/stdc++.h>
using namespace std;
struct Cord {
    int a, b;
};
bool compare(const Cord &x, const Cord &y) {
    return x.a < y.a;
}
int n;
vector<int> fenwick;
void update(int idx, int value) {
    while (idx <= 2 * n) {
        fenwick[idx] += value;
        idx += (idx & -idx);
    }
}
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += fenwick[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main() {
    cin >> n;
    vector<Cord> cords(n);
    fenwick.resize(2 * n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> cords[i].a >> cords[i].b;
        if (cords[i].a > cords[i].b) swap(cords[i].a, cords[i].b);
    }
    sort(cords.begin(), cords.end(), compare);
    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += query(cords[i].b - 1) - query(cords[i].a);
        update(cords[i].b, 1);
    }
    cout << result;
    return 0;
}
