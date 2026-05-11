#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, k, a[100001];
    cin>>m>>k;
    for(int i = 1; i<=m; i++)
        cin>>a[i];
    long long s = 0;
    int ans[100001];
    deque<int> dq;
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i<=m; i++){
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
        while(!dq.empty()&&dq.front() <= i-k)
            dq.pop_front();
        s += 2*a[dq.front()];
        ans[dq.front()] += 2;
    }
    cout<<s<<"\n";
    for(int i = 1; i<=m-1; i++)
        cout<<ans[i]<<" ";
    cout<<ans[m];
    return 0;
}
