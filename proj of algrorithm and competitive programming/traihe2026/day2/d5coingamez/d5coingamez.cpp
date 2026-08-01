#include <bits/stdc++.h>
#include "coingamelib.h"
using namespace std;

namespace personA{
    string send(string w) {return w;}
}
namespace personB{
    void play(string s) {
        int cnt=0,n=s.size();
        for(char c:s) {cnt+=(c=='0');}
        if(!cnt) return;
        if(cnt&1) {
            vector<int>p;
            for(int i=0; i<s.size(); ++i) {
                if(s[i]=='0') {p.push_back(i);}
            }
            int l=0,r=n-1;
            for(int i=0; i<p.size(); i+=2) {
                if(i!=p.size()-1) r=p[i+1]-1;
                else r=n-1;
                int cur=p[i];
                for(int j=cur; j>=l; --j) take(j);
                for(int j=cur+1; j<=r; ++j) take(j);
                if(i+1<p.size()) l=p[i+1];
            }
        }
        else {
            vector<int>p;
            for(int i=0; i<s.size(); ++i) {
                if(s[i]=='0') {p.push_back(i);}
            }
            int l=p[0]+2,r=n-1;
            for(int i=1; i<p.size(); i+=2) {
                if(i!=p.size()-1) r=p[i+1]-1;
                else r=n-1;
                int cur=p[i];
                for(int j=cur; j>=l; --j) take(j);
                for(int j=cur+1; j<=r; ++j) take(j);
                if(i+1<p.size()) l=p[i+1];
            }
            int cur=p[0];
            for(int j=cur; j>=0; --j) take(j);
        }
    }
}