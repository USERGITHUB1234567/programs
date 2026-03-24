#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, cnt[10];
    queue<pair<int, int>>q;
    cin>>n>>m;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i<=n-1; i++){
        int a;
        cin>>a;
        q.push({i, a});
        cnt[a]++;
    }
    int time = 0;
    for(int i = 9; i>=1; i--){
        while(cnt[i]>0){
            while(q.front().second!=i){
            q.push(q.front());
            q.pop();
        }
        time++;
        if(q.front().first==m){
            cout<<time;
            break;
        }
        cnt[q.front().second]--;
        q.pop();
        }
    }
    return 0;
}
