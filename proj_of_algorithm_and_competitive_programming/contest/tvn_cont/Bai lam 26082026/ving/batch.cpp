#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,s;
pair<int,int>batch[maxn];
namespace soup1{
    void implement() {
        int fm=(1<<(n-1));
        long long ans=1e18;
        for(int mask=0; mask<fm; ++mask) {
            int sum1=0,sum2=0,t=0;
            long long tmp=0;
            for(int i=0; i<n-1; ++i) {
                sum1+=batch[i+1].first,sum2+=batch[i+1].second;
                if(mask&(1<<i)) {
                    tmp+=(s+sum1+t)*sum2;
                    t+=s+sum1;
                    sum1=0,sum2=0;
                }
            }
            sum1+=batch[n].first,sum2+=batch[n].second;
            tmp+=(sum1+s+t)*sum2;
            ans=min(ans,tmp);
        }
        cout << ans;
    }
}
struct convex_hull_trick{
    vector<pair<long long,long long>>hull;
    double intersect(const pair<long long,long long>& l1, const pair<long long,long long>& l2) {
        return (double)(l1.second-l2.second)/(l2.first-l1.first);
    }
    bool bad(const pair<long long,long long>& l1, const pair<long long,long long>& l2, const pair<long long,long long>& l3) {
        return intersect(l1,l2)>=intersect(l2, l3);
    }
    void add(const pair<long long,long long>&l) {
        if(!hull.empty() && hull.back().first==l.first && hull.back().second<=l.second) return;
        while(hull.size()>=2 && bad(hull[hull.size()-2],hull.back(),l)) hull.pop_back();
        hull.push_back(l);
    }
    long long query(long long x) {
        int l=0,r=hull.size()-1;
        if(hull.empty()) return 0;
        if(hull.size()==1) {return hull[0].first*x+hull[0].second;}
        while(l<r) {
            int mid=(l+r)>>1;
            if(hull[mid].first*x+hull[mid].second<hull[mid+1].first*x+hull[mid+1].second) r=mid;
            else l=mid+1;
        }
        return hull[l].first*x+hull[l].second;
    }
}cht;
namespace soupfull{
    long long f[maxn],sumT[maxn],sumF[maxn];
    void implement() {
        for(int i=n; i>=1; --i) {sumF[i]=sumF[i+1]+batch[i].second;}
        for(int i=1; i<=n; ++i) {sumT[i]=sumT[i-1]+batch[i].first;}
        cht.add({sumF[1],0});
        for(int i=1; i<=n; ++i) {
            // long long query=cht.query(sumF[i]);
            // f[i]=query+(s+sumT[i])*sumF[i];
            // cht.add({-sumF[i],f[i]});
            f[i]=cht.query(s+sumT[i]);
            if(i<n) {
                long long m=sumF[i+1],c=f[i]-sumT[i]*sumF[i+1];
                cht.add({m,c});
            }
        }
        cout << f[n];
    }
    /*
=== CÔNG THỨC QUY HOẠCH ĐỘNG (DP) ===
- Gọi f[i] là tổng chi phí tối thiểu để xử lý các công việc từ 1 đến i.
- Gọi sumT[i] = T[1] + T[2] + ... + T[i] là tổng thời gian tiền tố.
- Gọi sufF[i] = F[i] + F[i+1] + ... + F[N] là tổng hệ số chi phí hậu tố.
- Công thức chuyển trạng thái O(N^2):
  f[i] = min_{0 <= j < i} { f[j] + (S + sumT[i] - sumT[j]) * sufF[j+1] }

=== BIẾN ĐỔI VỀ DẠNG HÀM SỐ BẬC NHẤT CHO CHT O(N) ===
Khai triển và nhóm các thành phần theo i (ẩn số x) và theo j (đường thẳng y = m * x + c):
  f[i] = min_{0 <= j < i} { (sufF[j+1]) * (S + sumT[i]) + (f[j] - sumT[j] * sufF[j+1]) }

- Hoành độ biến số (x): x = S + sumT[i]
- Hệ số góc của đường thẳng j (m): m = sufF[j+1]
- Tung độ gốc của đường thẳng j (c): c = f[j] - sumT[j] * sufF[j+1]
*/
}
namespace souptraurua{
    long long f[maxn];
    int t[maxn];
    void implement() {
        for(int i=1; i<=n; ++i) f[i]=2e9;
        for(int i=1; i<=n; ++i) {
            auto[sum1,sum2]=batch[i];
            for(int j=i-1; j>=0; --j) {
                //f[i]=min(f[i],f[j]+(s+sum1)*sum2);
                if(f[i]>f[j]+(s+sum1+t[j])*sum2) {
                    f[i]=min(f[i],f[j]+(s+sum1+t[j])*sum2);
                    t[i]=t[j]+(s+sum1);
                }else if(f[i]==f[j]+(s+sum1+t[j])*sum2) {
                    t[i]=min(t[i],t[j]+s+sum1);
                }
                sum1+=batch[j].first,sum2+=batch[j].second;
            }
        }
        // for(int i=1; i<=n; ++i) cout << t[i] << ' ';
        // cout << '\n';
        // for(int i=1; i<=n; ++i) cout << f[i] << ' ';
        // cout << '\n';
        cout << f[n];
    }
}
namespace souptrau{
    long long f[maxn];
    int suf[maxn];
    void implement() {
        for(int i=n; i>=1; --i) {suf[i]=suf[i+1]+batch[i].second;f[i]=1e18;}
        for(int i=1; i<=n; ++i) {
            int sum1=0,sum2;
            for(int j=i-1; j>=0; --j) {
                sum1+=batch[j+1].first;
                sum2=suf[j+1];
                if(f[i]>f[j]+(s+sum1)*sum2) {
                    f[i]=min(f[i],f[j]+(s+sum1)*sum2);
                }
            }
        }
        cout << f[n];
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    // freopen("batch.inp", "r", stdin);
    // freopen("batch.out", "w", stdout);
    cin >> n >> s;
    for(int i=1; i<=n; ++i) cin >> batch[i].first >> batch[i].second;
    // if(n<=25) soup1::implement();
    // else souptraurua::implement();
    soupfull::implement();
}
/*
2
50
100 100
100 100

5
1
1 3
3 2
4 3
2 3
1 4
*/
