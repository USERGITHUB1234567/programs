#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    string s;
    cin >> c;
    cin >> s;
    int a[2];
    int h;
    if(c=='N') h=0;
    if(c=='W') h=1;
    if(c=='S') h=2;
    if(c=='E') h=3;
    for(int i=0; i<s.size(); i++) {
        a[1]=0;
        a[0]=0;
        if(s[i]==')') continue;
        if(s[i]=='L') {
            h=(h+1)%4;
            continue;
        }
        if(s[i]=='R') {
            if(h-1==-1) h=3;
            else h-=1;
            continue;
        }
        if(isdigit(s[i])) {
            string s1;
            s1+=s[i];
            int t=stoi(s1);
            if(isalpha(s[i+1])) {

                if(s[i]=='L') {
                    //while(t--) {
                        h=(h+t)%4;
                    //}
                }
                if(s[i]='R') {
                    //while(t--) {
                        //if(h-1==-1) h=3;
                        //else h-=1;
                        h=(((h-t)%4)+4)%4;
                    //}
                }
                i++;
                continue;
            }
            for(int j=i+2; j<s.size(); j++) {
                if(s[j]==')') break;
                if(s[j]=='L') a[0]++;
                else a[1]++;
            }
            int l=max(a[0],a[1])-min(a[0],a[1]);
            if(max(a[0],a[1])==a[0]) {
                h=(h+(t*l))%4;
            }
            else {
                h=((h-(t*l))%4+4)%4;
            }
            //cout << t << " ";

            i+=a[0]+a[1]+1;
        }//cout << h << " " << i <<  endl;
    }
    //cout << h << endl;
    if(h==0) cout << 'N';
    if(h==1) cout << 'W';
    if(h==2) cout << 'S';
    if(h==3) cout << 'E';
    /*string s="1";
    int n=stoi(s);
    cout << n;*/
}
