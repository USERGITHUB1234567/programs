#include <bits/stdc++.h>
using namespace std;
int n,x[10],cnt=0;
int used[10];
void dfs(int i)
{
    if(i>n) {
        for(int j=1; j<=n; j++) {
            if(x[j]==j) return;
        }
        cnt++;
        for(int j=1; j<=n-1; j++) cout << x[j] << " ";
        cout << x[n] << "\n";
        return;
    }
    for(int j=1; j<=n; j++) {
        if(!used[j]) {
            x[i]=j;
            used[j]=true;
            dfs(i+1);
            used[j]=false;
        }
    }
}
int main()
{
    cin >> n;
    memset(used,false,sizeof(used));
    dfs(1);
    cout << cnt;
}
