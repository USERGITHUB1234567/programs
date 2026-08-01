#include <bits/stdc++.h>
using namespace std;
int n, k,x[10];
bool used[16];
void dfs(int i)
{
    if(i>k) {
        for(int j=1; j<=k-1; j++)
            cout << x[j] << " ";
        cout << x[k] << "\n";
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
    cin >> k >> n;
    long long nf=1,nmk=1;
    for(int i=1; i<=n; i++) {
        nf*=i;
        if(i<=n-k) nmk*=i;
    }
    cout << nf/nmk << "\n";
    dfs(1);
    return 0;
}
