bool g(string X) {
    int n = X.size();
    if (n == 0)
        return true;
    int mid = n >> 1;
    int cnt[10] = {0};
    for (char c : X)
        ++cnt[c - '0'];
    vector<int>rem;
    for (int d = 0; d < 10; ++d)
        if (cnt[d] % 4 != 0)
            rem.push_back(cnt[d] % 4);
    sort(all(rem));
    if (n % 2 == 0) {
        if (mid % 2 == 0)
            return rem.empty();
        else
            return (rem.size() == 1 && rem[0] == 2);
    }
    else {
        if (mid % 2 == 0)
            return (rem.size() == 1 && rem[0] == 1);
        else {
            if (rem.size() == 1)
                return (rem[0] == 3);
            else if (rem.size() == 2)
                return (rem[0] == 1 && rem[1] == 2);
            return false;
        }
    }
}
