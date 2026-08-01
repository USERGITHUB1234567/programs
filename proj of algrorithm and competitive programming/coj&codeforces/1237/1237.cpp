#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, d, cnt = 0;
    cin >> n >> d;
    vector<pair<long long, long long>> a(n + 1);
    for (long long i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    multiset<long long> x, y;
    long long l = 1, r = 1;
    for (long long i = 1; i <= n; i++){
        while(a[i].first - a[l].first > d){
            x.erase(x.find(a[l].second));
            l++;
        }
        x.insert(a[i].second);
        while (r <= n && a[r].first - a[i].first <= d){
            y.insert(a[r].second);
            r++;
        }
        if (*(--x.end()) >= 2 * a[i].second && *(--y.end()) >= 2 * a[i].second){
            cnt++;
        }
        y.erase(y.find(a[i].second));
    }
    cout << cnt;
    return 0;
}
