#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    multiset<int>st;
    //st.insert(1);
    //st.insert(2);
    st.insert(1);
    st.insert(9);
    auto it=st.find(7);
    cout << (it==st.end());
}