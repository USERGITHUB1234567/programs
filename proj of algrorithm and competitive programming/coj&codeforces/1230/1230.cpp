#include <bits/stdc++.h>
#pragma GCC oprimize("O3")
using namespace std;
int n;
struct point
{
    int id,x,y;
    double g,d;
}a[100001];
bool cmp(point a, point b)
{
    return (a.g<b.g) or ((a.g==b.g) and (a.d<b.d));
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id=i;
    }
    for(int i=2; i<=n; i++) {
        if((a[i].y < a[1].y) or (a[i].y == a[1].y and a[i].x>a[1].x)) swap(a[1],a[i]);
    }
    for(int i=2; i<=n; i++) {
        a[i].g=atan2(a[i].y-a[1].y,a[i].x-a[1].x);
        a[i].d=sqrt(1.0*(a[i].x-a[1].x)*(a[i].x-a[1].x)+1.0*(a[i].y-a[1].y)*(a[i].y-a[1].y));
    }
    sort(a+2,a+1+n,cmp);
    for(int i=n; i>=2; i--) {
        if(a[i].g!=a[i-1].g) {
            for(int j=i; j<=(n+i)/2; j++) swap(a[j],a[n+i-j]);
            break;
        }
    }
    for(int i=1; i<=n; i++) cout << a[i].id << "\n";
    return 0;
}
