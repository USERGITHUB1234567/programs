#include <bits/stdc++.h>
using namespace std;
const int block_size=450,lim=200000;
int q,total[block_size];
struct fenwick_tree{
    int n;
    vector<int>bit;
    fenwick_tree(int _n):n(_n) {bit.assign(n+1,0);}
    void add(int i, int v) {
        while(i<=n) {
            bit[i]+=v;
            i+=i&-i;
        }
    }
    int sum(int i) {
        int res=0;
        while(i) {
            res+=bit[i];
            i-=i&-i;
        }
        return res;
    }
    void range_add(int i, int j, int v) {
        add(i,v);
        add(j+1,-v);
    }
};
int main(int argc, char** argv) {
    cin >> q;
    fenwick_tree fen(lim);
    while(q--) {
        string type;cin >> type;
        int x,k;
        if(type=="ADD") {
            cin >> x >> k;
            if(k<block_size) {
                total[k]+=x;
            }
            else {
                for(int i=1; i<=lim; i+=(k<<1)) {
                    fen.range_add(i,i+k-1,x);
                }
            }
        }else if(type=="DEL") {
            cin >> x >> k;
            if(k<block_size) {
                total[k]-=x;
            }
            else {
                for(int i=1; i<=lim; i+=(k<<1)) {
                    fen.range_add(i,i+k-1,-x);
                }
            }
        }else {
            cin >> x;
            int ans=fen.sum(x);
            for(int k=1; k<block_size; ++k) {
                if(!(((x-1)/k)&1)) ans+=total[k];
            }
            cout << ans << '\n';
        }
    }
}