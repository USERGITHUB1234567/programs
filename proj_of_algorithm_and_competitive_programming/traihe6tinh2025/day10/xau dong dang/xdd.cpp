#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s,t;
bool mk1[26],mk2[26];
map<char,char>mp1,mp2;
void temp() {
	cin >> s >> t;
	bool ck=true;
	for(int i=0; i<s.size(); i++) {
		if(!mk1[s[i]-'a'] && !mk2[t[i]]-'a') {
			mp1[s[i]]=t[i];
			mp2[t[i]]=s[i];
			mk1[s[i]-'a']=true;
			mk2[t[i]-'a']=true;
		}
		else {
			if(mp1[s[i]]!=t[i] || mp2[t[i]]!=s[i]) {
				ck=false;
				break;
			}
		}
	}
	cout << (ck?"YES":"NO");
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	temp();
}