#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Farmer {
    int price;
    int amount;
};

bool compare(Farmer a, Farmer b) {
    return a.price < b.price;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<Farmer> farmers(M);
    for (int i = 0; i < M; ++i) {
        cin >> farmers[i].price >> farmers[i].amount;
    }
    sort(farmers.begin(), farmers.end(), compare);

    int total_cost = 0;
    for (int i = 0; i < M && N > 0; ++i) {
        int milk_to_buy = min(N, farmers[i].amount);
        total_cost += milk_to_buy * farmers[i].price;
        N -= milk_to_buy;
    }
    cout << total_cost;
    return 0;
}
