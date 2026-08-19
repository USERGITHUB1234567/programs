#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct point {
    int x, y;
};

struct event {
    point p1, p2;
    int type;
};

bool cmp(event e1, event e2) {
    return (e1.p1.x < e2.p1.x) || (e1.p1.x == e2.p1.x && e1.type < e2.type) || (e1.p1.x == e2.p1.x && e1.type == e2.type && e1.p1.y < e2.p2.y);
}

int main() {
    int n;
    cin >> n;
    vector<event> e;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) {
            if (x1 > x2) swap(x1, x2);
            e.push_back({{x1, y1}, {x2, y2}, 0});
            e.push_back({{x2, y2}, {x1, y1}, 2});
        } else {
            if (y1 > y2) swap(y1, y2);
            e.push_back({{x1, y1}, {x2, y2}, 1});
        }
    }
    sort(e.begin(), e.end(), cmp);
    vector<point> res;
    set<int> s;
    for (auto a : e) {
        if (a.type == 0) s.insert(a.p1.y);
        else if (a.type == 1) {
            auto it = s.lower_bound(a.p1.y);
            for (; it != s.end() && (*it) <= a.p2.y; it++) res.push_back({a.p1.x, *it});
        } else s.erase(a.p1.y);
    }
    cout << res.size() << "\n";
    for (auto b : res) {
        cout << b.x << " " << b.y << "\n";
    }
    return 0;
}
