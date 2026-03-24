#include <bits/stdc++.h>
using namespace std;
string s;
int main(int argc, char** argv) {
    getline(cin,s);
    istringstream iss(s);
    while(iss) {
        string t;
        iss >> t;
        cout << t << '\n';
    }
}