#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1000001;
int BIT[MAXX] = {0};
void upd(int idx, int val) {
    while(idx < MAXX) {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}
int qry(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--){
        int tp, x;
        cin >> tp >> x;
        if(tp == 0) {
            upd(x, 1);
        } else {
            cout << qry(x) << "\n";
        }
    }

    return 0;
}
