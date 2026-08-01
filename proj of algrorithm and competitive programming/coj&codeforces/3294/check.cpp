#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    system("g++ -std=c++26 gen.cpp -o gen");
    system("g++ -std=c++26 3294.cpp -o 3294");
    system("g++ -std=c++26 ans.cpp -o ans");
    int tc=8;
    while(tc--) {
        system("./gen");
        vector<string>t1,t2;
        string s;
        system("./ans");
        ifstream ifs1("3294.out");
        while(ifs1>>s) t1.push_back(s);
        system("./3294");
        ifstream ifs2("3294.out");
        while(ifs2>>s) t2.push_back(s);
        cout << (t1==t2?"AC":"WA") << '\n';
    }
}