#include <bits/stdc++.h>
using namespace std;

bool canPlayAllCards(vector<vector<int>>& cards, vector<int>& order) {
    int n = cards.size();
    int m = cards[0].size();
    int topCard = -1;

    for (int round = 0; round < m; ++round) {
        for (int i = 0; i < n; ++i) {
            int cow = order[i];
            auto it = upper_bound(cards[cow].begin(), cards[cow].end(), topCard);
            if (it == cards[cow].end()) {
                return false;
            }
            topCard = *it;
            cards[cow].erase(it);
        }
    }
    return true;
}

vector<int> findOrder(int n, int m, vector<vector<int>>& cards) {
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }

    do {
        vector<vector<int>> tempCards = cards;
        if (canPlayAllCards(tempCards, order)) {
            return order;
        }
    } while (next_permutation(order.begin(), order.end()));

    return {-1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> cards(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> cards[i][j];
            }
            sort(cards[i].begin(), cards[i].end());
        }

        vector<int> order = findOrder(n, m, cards);
        if (order[0] == -1) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < n; ++i) {
                cout << order[i] + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
