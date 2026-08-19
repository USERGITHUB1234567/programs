#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int maxn=1000006;
/*
Subtask 1, 2:
Gọi 𝑑𝑝𝑖 là chi phí tối thiểu để lát tất cả các điểm từ điểm thứ nhất đến điểm thứ 𝑖. Ta có:
𝑑𝑝𝑖 = {0 min
với 𝑖 = 0
𝑗=1,2,…,𝑖 (𝑑𝑝𝑗−1 + 𝑐 + (𝑥𝑗− 𝑥𝑖)2) với 𝑖 = 1, 2, … , 𝑛
Khi đó chi phí tối thiểu để lát tất cả 𝑛 điểm là 𝑑𝑝𝑛.
Độ phức tạp của thuật toán là 𝑂(𝑛2).
Subtask 3:
Ta biến đổi:
min
𝑗=1,2,…,𝑖 (𝑑𝑝𝑗−1 + 𝑐 + (𝑥𝑗− 𝑥𝑖)2)
= min
𝑗=1,2,…,𝑖(𝑑𝑝𝑗−1 + 𝑐 + 𝑥𝑗
2
− 2𝑥𝑗𝑥𝑖 + 𝑥𝑖
2)
= min
𝑗=1,2,…,𝑖 ((−2𝑥𝑗)𝑥𝑖 + 𝑑𝑝𝑗−1 + 𝑥𝑗
2) + 𝑐 + 𝑥𝑖
2
Ta có thể tính nhanh min
𝑗=1,2,…,𝑖 ((−2𝑥𝑗)𝑥𝑖 + 𝑑𝑝𝑗−1 + 𝑥𝑗
2) bằng kĩ thuật bao lồi với tập các đường
thẳng 𝑦 = 𝑎𝑗𝑥 + 𝑏 𝑗 có hệ số góc 𝑎𝑗 = −2𝑥𝑗, hệ số tự do 𝑏 𝑗 = 𝑑𝑝𝑗−1 + 𝑥𝑗
2 và các truy vấn tại 𝑥 =
𝑥𝑖.
Theo giả thiết các 𝑥𝑖 có thứ tự tăng dần nên các đường thẳng đã được sắp xếp theo hệ số góc giảm
dần. Vì trong kĩ thuật bao lồi, các đường thẳng đưa vào bao lồi cần theo thứ tự hệ số góc giảm dần
nên ta không cần phải sắp xếp lại các đường thẳng này nữa. Hơn nữa không có hai đường thẳng nào
có cùng hệ số góc, nên ta cũng không phải xử lý trường hợp có hai đường thẳng song song.
Mặt khác các truy vấn tại 𝑥 = 𝑥𝑖 cũng được sắp xếp tăng dần. Như vậy thay vì tìm kiếm nhị phân
cho từng truy vấn, ta có thể chỉ cần tìm kiếm tuần tự một lần để trả lời cho tất cả các truy vấn.
Độ phức tạp của thuật toán là 𝑂(𝑛).
*/
struct line
{
    long long a,b;
}li[maxn];
long long x[maxn],f[maxn],n,c;
vector<line>hull;
bool bad(line l1, line l2, line l3)
{
    return (long double)(l3.b-l1.b)/(l1.a-l3.a)<=(long double)(l2.b-l1.b)/(l1.a-l2.a);
}
void add(line l)
{
    if(!hull.empty() && hull.back().a==l.a && hull.back().b==l.b) return;
    if(!hull.empty() && hull.back().a==l.a && hull.back().b>l.b) hull.pop_back();
    hull.push_back(l);
    while(hull.size()>=3 && bad(hull[hull.size()-3],hull[hull.size()-2],hull[hull.size()-1])) hull.erase(hull.end()-2);
}
long long query(long long x)
{
    int l=0, r=hull.size()-1;
    while(l<r) {
        int mid=(l+r)>>1;
        long long v1=hull[mid].a*x+hull[mid].b,v2=hull[mid+1].a*x+hull[mid+1].b;
        if(v1<=v2) r=mid;
        else l=mid+1;
    }
    return hull[l].a*x+hull[l].b;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> c;
    for(int i=1; i<=n; i++) cin >> x[i];
    //f[1]=c;
    //add({-2LL*x[1],f[1]+x[1]*x[1]});
    for(int i=1; i<=n; i++){
        add({-2LL*x[i],f[i-1]+x[i]*x[i]});
        f[i]=x[i]*x[i]+c+query(x[i]);

    }
    cout << f[n];
}
