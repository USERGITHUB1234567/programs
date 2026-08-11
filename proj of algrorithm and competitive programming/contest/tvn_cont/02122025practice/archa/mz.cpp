#include <bits/stdc++.h>
using namespace std;

int ma[29],mb[29];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("archa.inp", "r", stdin);
    freopen("archa.out", "w", stdout);
    unordered_map<char,int> mp; // chosen
    
    int n; cin >> n;
    string s; cin >> s;
    int dodai=s.size();
    char dou='a';
    for(int i=0;i<dodai;i++)
    {
        mp[s[i]]++;
        //if(mp[s[i]]%2==1) dou=s[i];
    }
    int count=0;
    for(int i=0;i<dodai;i++)
    {
        //mp[s[i]]++;
        if(mp[s[i]]%2==1) 
        {
            if(mp[s[i]]>count)
            {
                dou=s[i];
                count=mp[s[i]];
            }
        }
    }
    //cout << doub;
    string a="", b="";
    int count_dou_a=0,count_dou_b=0;
    for(int i=0;i<dodai/2;i++)
    {
        a+=s[i];
        if(s[i]==dou) count_dou_a++;
        //ma[int(s[i])-97]++;
    }
    for(int i=dodai/2;i<dodai;i++) 
    {
        b+=s[i];
        if(s[i]==dou) count_dou_b++;
        //mb[int(s[i])-97]++;
    }
    
    cout << dou <<'\n';
    if(count_dou_a>count_dou_b) 
    {
        
        b.erase(0,1);
        if(n==1) reverse(b.begin(),b.end());
        cout << b;
    }
    else
    {
        if(n==1) reverse(a.begin(),a.end());
        cout << a;
    }
    
}
