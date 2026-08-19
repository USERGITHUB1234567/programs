#include <bits/stdc++.h>
#include "cave.h"
using namespace std;
namespace soup1{
    void implement(int n) {
        int j=0,s[n];
        for(int i=0; i<n; ++i) s[i]=0;
        for(int i=1; i<=n; ++i) {
            int get=tryCombination(s);
            if(get==i-1) s[i-1]=1;
        }
        int d[n];for(int i=1; i<=n; ++i) d[i-1]=i-1;
        answer(s,d);
    }
}
namespace soup2{
    void implement(int n) {
        int s[n],d[n];
        for(int i=0; i<n; ++i) s[i]=0;
        for(int i=0; i<n; ++i) {
            s[i]=1;
            int get=tryCombination(s);
            d[i]=get;
            s[i]=0;
        }
        answer(s,d);
    }
}
namespace soupfull{
    void implement(int n) {
        int s[n],d[n];
        bool mk[n];
        for(int i=0; i<n; ++i) mk[i]=false;
        for(int i=0; i<n; ++i) {
            int test[n];
            for(int j=0; j<n; ++j) {
                if(mk[j]) test[j]=s[j];
                else test[j]=0;
            }
            int get=tryCombination(test);
            int correct=(get>i || get==-1?0:1);
            int l=0,r=n-1,ans;
            while(l<=r) {
                if(l==r) {ans=l;break;}
                int mid=(l+r)>>1;
                for(int j=0; j<n; ++j) {
                    if(mk[j]) test[j]=s[j];
                    else if(j>=j && j<=mid) test[j]=correct;
                    else test[j]=1-correct;
                }
                int t=tryCombination(test);
                if(t>i || t==-1) r=mid;
                else l=mid+1;
            }
            d[ans]=i;
            s[ans]=correct;
            mk[ans]=true;
        }
        answer(s,d);
    }
    
}
void exploreCave(int n) {
    //soup1::implement(n);
    //soup2::implement(n);
    soupfull::implement(n);
}