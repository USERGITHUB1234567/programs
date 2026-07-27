#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    system("g++ -std=c++26 gen.cpp -o gen");
    system("g++ -std=c++26 3293.cpp -o 3293");
    system("g++ -std=c++26 ans.cpp -o ans");
    int tc=100;
    //system("./ans");
    while(tc--) {
        system("./gen");
        system("./3293");
        ifstream ifs("3293.out");
        string s;
        vector<string>t1,t2;
        while(ifs>>s) t1.push_back(s);
        system("./ans");
        ifstream ifs2("3293.out");
        while(ifs2>>s) t2.push_back(s);
        cout << (t1==t2?"AC well done for your effort":"WA please check your code again") << '\n';
    }
}