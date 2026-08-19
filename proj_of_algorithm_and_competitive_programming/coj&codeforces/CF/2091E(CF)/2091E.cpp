#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int mn=10000007;
bool era[mn];
void snt()
{
    memset(era,true,sizeof(era));
    era[0]=era[1]=false;
    for(int i=2; i*i<=mn; i++) {
        if(era[i]) {
            int j=i*i;
            while(j<=mn) {
                era[j]=false;
                j+=i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin >> t;
    snt();
    while(t--) {
        int n;
        cin >> n;
        long long ans=0;
        for(int i=2; i<=n; i++) {
            if(era[i]) {
                ans+=n/i;
            }
        }
        cout << ans << "\n";
    }
}
