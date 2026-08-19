#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment {
    long long l, r;
};

long long findKthNumber(vector<Segment>& segments, long long k) {
    long long left = -2e9, right = 2e9;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long count = 0;
        for (const auto& seg : segments) {
            if (seg.l <= mid) {
                count += min(mid, seg.r) - seg.l + 1;
            }
        }
        if (count > k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].l >> segments[i].r;
    }
    cout << findKthNumber(segments, k) << endl;
    return 0;
}
