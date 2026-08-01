#include <bits/stdc++.h>
using namespace std;
int n, k, p, q;
bool check(int a, int b, int c){
    int x = c%k, pos = p;
    for(int i = 1; i<=n; i++){
        int u = x % k+1, v = (x+1) % k + 1;
        if(u == pos) pos = v;
        else
            if(v==pos) pos = u;
        x = (x * a + b) % k;
    }
    return pos == q;
}
int main()
{
    cin>>n>>k>>p>>q;
    for(int a = 0; a<=k-1; a++)
        for(int b = 0; b<=k-1; b++)
            for(int c = 0; c<=k-1; c++)
                if (check(a, b, c)){
                    cout<<a<<" "<<b<<" "<<c;
                    return 0;
                }
    cout<<"Impossible";
    return 0;
}
