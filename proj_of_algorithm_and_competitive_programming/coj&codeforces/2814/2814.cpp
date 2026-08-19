/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n,tree[10009];
vector<tuple<int,int,int>>hor,ver;
void bulid()
{
    memset(tree,0,sizeof(tree));
}
void update(int i,int v)
{
    while(i<=10001) {
        tree[i]+=v;
        i+=i & -i;
    }
}
void sum(int i)
{
    long long s=0;
    while(i>=0) {
        s+=tree[i];
        i-=i&-i;
    }
}
bool interse(tuple<int,int,int> h, tuple<int,int,int> v)
{
    return get<0>v(v)>=get<0>(h) and get<0>(v)<=get<1>(h) and get<2>(h)>=get<1>(v) and get<2>(h) <=get<2>(v);
}
void sub3()
{
    cin >> n;
    for(int i=1; i<=n; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1+=5001;
        y1+=5001;
        x2+=5001;
        y2+=5001;
        if(x1==x2) {
            if(y1>y2) swap(y1,y2);
            ver.push_back({y1,y2,x1});
        }
        else {
            if(x1>x2) swap(x1,x2);
            hor.push_back({x1,x2,y1});
        }
    }
    long long ans=0;
    for(int r=1; r<ver.size(); r++) {
        for(int l=0; l<r; l++) {
            build();
            for(int i=0; i<hor.size() and get<0>(hor[i])<=get<0>(ver[l]); i++) {
                if(get<1>(hor[i])<get<0>(ver[r]) or get<1>(hor[i])<get<0>(ver[r]) or get<2>(hor[i])>get<2>(ver[r])) continue;
                update(get<2>(hor[i],1));
            }
        }
        int cnt=sum(get<2>(ver[l]))-sum(get<1>(ver[l])-1);
        ans+=cnt*(cnt-1)/2;
    }
    cout << ans;
}
int main()
{
    sub3();
    exit(0);
}*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int MAX_COORD = 10001;
int n, tree[MAX_COORD + 1];
vector<tuple<int, int, int>> hor, ver;
void build() {
    memset(tree, 0, sizeof(tree));
}
void update(int i, int v) {
    while (i <= MAX_COORD) {
        tree[i] += v;
        i += i & -i;
    }
}
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += tree[i];
        i -= i & -i;
    }
    return s;
}
void sub3() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 5001;
        y1 += 5001;
        x2 += 5001;
        y2 += 5001;
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            ver.push_back({y1, y2, x1});
        } else {
            if (x1 > x2) swap(x1, x2);
            hor.push_back({x1, x2, y1});
        }
    }
    sort(ver.begin(), ver.end());
    sort(hor.begin(),hor.end());
    long long ans = 0;
    for (size_t r = 0; r < ver.size(); r++) {
        for (size_t l = 0; l < r; l++) {
            build();
            int x1 = get<2>(ver[l]), x2 = get<2>(ver[r]);
            if (x1 > x2) swap(x1, x2);
            for (auto& h : hor) {
                int hx1 = get<0>(h), hx2 = get<1>(h), hy = get<2>(h);
                if (hx1 <= x1 && hx2 >= x2) {
                    update(hy, 1);
                }
            }
            int y1 = max(get<0>(ver[l]), get<0>(ver[r]));
            int y2 = min(get<1>(ver[l]), get<1>(ver[r]));
            if (y1 <= y2) {
                int cnt = sum(y2) - sum(y1 - 1);
                ans += cnt * (cnt - 1) / 2;
            }
        }
    }
    cout << ans;
}
int main() {
    sub3();
    return 0;
}
