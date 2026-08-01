#include <bits/stdc++.h>
using namespace std;

int n,x[10];
bool used[10];
void dfs(int i)
{
    if(i>n) {
        for(int j=1; j<n; j++)
            cout << x[j] << " ";
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
    long long t=1;
    for(long long i=1; i<=n; i++) t*=i;
    cout << t << "\n";
    dfs(1);
    return 0;
}
