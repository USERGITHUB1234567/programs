#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;  // Số đỉnh tối đa (có thể điều chỉnh)

int parent[MAX];         // Mảng cha: parent[i] chứa cha của đỉnh i
int sz[MAX];             // Mảng kích thước: sz[i] chứa kích thước của tập hợp có đỉnh i làm đại diện

// History lưu lại các thay đổi khi thực hiện union.
// Mỗi phần tử trong history là một cặp (node, oldSize):
// - node: đỉnh được gộp (đã có parent khác trước khi union)
// - oldSize: kích thước của tập hợp đại diện (trước khi cập nhật)
// Nếu không thực sự gộp (hai đỉnh đã thuộc cùng 1 tập) thì ta lưu một cặp dummy (-1, -1)
vector<pair<int, int>> history;

// Hàm khởi tạo DSU cho n đỉnh (đánh số từ 0 đến n-1)
void initDSU(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

// Tìm đại diện của tập chứa đỉnh a (không sử dụng path compression)
int findDSU(int a) {
    while (a != parent[a])
        a = parent[a];
    return a;
}

// Thực hiện union hai tập chứa đỉnh a và đỉnh b, đồng thời lưu lại lịch sử để rollback sau này.
// Nếu hai đỉnh đã cùng tập, lưu một ghi nhận dummy (-1, -1) để duy trì tính đồng bộ của stack.
bool unionDSU(int a, int b) {
    a = findDSU(a);
    b = findDSU(b);
    if (a == b) {
        history.push_back({-1, -1});
        return false;
    }
    // Union theo kích thước: tập có kích thước lớn sẽ làm cha của tập có kích thước nhỏ hơn.
    if (sz[a] < sz[b])
        swap(a, b);
    // Lưu lại trạng thái của tập đại diện a trước khi cập nhật,
    // lưu (b, sz[a]) với mục đích rollback sau này.
    history.push_back({b, sz[a]});
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

// Trả về snapshot hiện tại của DSU (tức là số lượng thao tác đã lưu trong history)
int snapshot() {
    return history.size();
}

// Rollback thao tác union cuối cùng.
void rollback() {
    if (history.empty())
        return;
    pair<int, int> last = history.back();
    history.pop_back();
    // Nếu ghi nhận dummy, không làm thay đổi gì
    if (last.first == -1 && last.second == -1)
        return;
    int b = last.first;        // Đỉnh b đã được gộp
    int oldSize = last.second;   // Kích thước của đại diện ban đầu (trước khi union)
    int a = parent[b];          // Sau union, a là đại diện của b
    sz[a] = oldSize;           // Khôi phục lại kích thước của tập hợp chứa a
    parent[b] = b;             // Khôi phục b thành thành phần riêng
}

// Rollback về trạng thái snapshot đã lưu (rollback cho đến khi history có kích thước bằng snap)
void rollback_to(int snap) {
    while ((int)history.size() > snap)
        rollback();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5; // Số đỉnh ví dụ (0 đến 4)
    initDSU(n);

    // Lưu trạng thái ban đầu
    int snap = snapshot();

    // Thực hiện vài phép union
    unionDSU(0, 1);
    unionDSU(1, 2);

    // Đếm số thành phần liên thông hiện tại
    int comp = 0;
    for (int i = 0; i < n; i++){
        if (findDSU(i) == i)
            comp++;
    }
    cout << "Số thành phần liên thông sau union: " << comp << "\n";

    // Rollback về trạng thái ban đầu
    rollback_to(snap);

    comp = 0;
    for (int i = 0; i < n; i++){
        if (findDSU(i) == i)
            comp++;
    }
    cout << "Số thành phần liên thông sau rollback: " << comp << "\n";

    return 0;
}
