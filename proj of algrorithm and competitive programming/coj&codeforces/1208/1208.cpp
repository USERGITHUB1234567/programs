#include <iostream>
#include <algorithm>
using namespace std;

struct Rectangle {
    int x1, x2, y1, y2;
};

int intersection_area(Rectangle rects[], int n) {
    int x1 = rects[0].x1, x2 = rects[0].x2;
    int y1 = rects[0].y1, y2 = rects[0].y2;

    for (int i = 1; i < n; ++i) {
        x1 = max(x1, rects[i].x1);
        x2 = min(x2, rects[i].x2);
        y1 = max(y1, rects[i].y1);
        y2 = min(y2, rects[i].y2);
    }

    if (x1 < x2 && y1 < y2) {
        return (x2 - x1) * (y2 - y1);
    } else {
        return 0;
    }
}

int main() {
    int n;
    cin >> n;
    Rectangle rects[n];
    for (int i = 0; i < n; ++i) {
        cin >> rects[i].x1 >> rects[i].x2 >> rects[i].y1 >> rects[i].y2;
    }

    cout << intersection_area(rects, n);
    return 0;
}
