#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

long long gv(int n, long long x, long long y) {
    if(n == 1) {
        if(x == 1 && y == 1) return 1;
        if(x == 2 && y == 2) return 2;
        if(x == 2 && y == 1) return 3;
        if(x == 1 && y == 2) return 4;
    }
    long long h = 1LL << (n - 1);
    long long t = h * h;
    long long of = 0;
    long long a, b;
    if(x <= h && y <= h) {
        of = 0;
        a = x;
        b = y;
    } else if(x > h && y > h) {
        of = t;
        a = x - h;
        b = y - h;
    } else if(x > h && y <= h) {
        of = 2 * t;
        a = x - h;
        b = y;
    } else {
        of = 3 * t;
        a = x;
        b = y - h;
    }
    return of + gv(n - 1, a, b);
}

pair<long long, long long> gc(int n, long long d) {
    if(n == 1) {
        if(d == 1) return {1, 1};
        if(d == 2) return {2, 2};
        if(d == 3) return {2, 1};
        if(d == 4) return {1, 2};
    }
    long long h = 1LL << (n - 1);
    long long t = h * h;
    int q = (d - 1) / t;
    long long r = d - q * t;
    auto p = gc(n - 1, r);
    long long x = 0, y = 0;
    if(q == 0) {
        x = p.first;
        y = p.second;
    } else if(q == 1) {
        x = p.first + h;
        y = p.second + h;
    } else if(q == 2) {
        x = p.first + h;
        y = p.second;
    } else {
        x = p.first;
        y = p.second + h;
    }
    return {x, y};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        while(q--){
            string o;
            cin >> o;
            if(o == "->") {
                long long x, y;
                cin >> x >> y;
                cout << gv(n, x, y) << "\n";
            } else if(o == "<-") {
                long long d;
                cin >> d;
                auto p = gc(n, d);
                cout << p.first << " " << p.second << "\n";
            }
        }
    }
    return 0;
}
