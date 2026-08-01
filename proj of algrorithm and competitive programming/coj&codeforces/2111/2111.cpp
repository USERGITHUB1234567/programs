#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n) : n(n) {
        tree.assign(n+1, 0);
    }
    void update(int i, int delta) {
        for(; i <= n; i += i & -i)
            tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for(; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }
};

struct Programmer {
    int A, H, idx;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Programmer> prog(N);
    for (int i = 0; i < N; i++){
        cin >> prog[i].A >> prog[i].H;
        prog[i].idx = i;
    }

    // Sắp xếp theo A tăng dần, nếu bằng thì theo H tăng dần.
    sort(prog.begin(), prog.end(), [](const Programmer &p1, const Programmer &p2){
        return (p1.A == p2.A) ? (p1.H < p2.H) : (p1.A < p2.A);
    });

    int maxH = 100000; // theo ràng buộc: 1 ≤ H ≤ 10^5
    Fenwick bit(maxH);
    vector<int> ans(N, 0);

    for (int i = 0; i < N; ) {
        int j = i;
        // Xác định nhóm có cùng (A, H)
        while(j < N && prog[j].A == prog[i].A && prog[j].H == prog[i].H)
            j++;

        // Truy vấn BIT: đếm số lập trình viên đã xử lý có H <= prog[i].H
        int cntBefore = bit.query(prog[i].H);
        for (int k = i; k < j; k++){
            ans[prog[k].idx] = cntBefore;
        }

        // Cập nhật BIT với toàn bộ nhóm hiện tại
        int groupSize = j - i;
        bit.update(prog[i].H, groupSize);
        i = j;
    }

    // In kết quả theo thứ tự ban đầu
    for (int i = 0; i < N; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
