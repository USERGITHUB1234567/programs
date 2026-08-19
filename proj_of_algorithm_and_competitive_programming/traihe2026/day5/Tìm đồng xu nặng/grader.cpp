#include "coins.h"
#include <iostream>

const int _MAX_CALLS = 10000;

std::vector<bool> _heavyOrLight, _used;
int _cnt_calls = 0;

int ask(const std::vector<int> &a, const std::vector<int> &b)
{
    if (++_cnt_calls > _MAX_CALLS)
    {
        std::cerr << "Maximum number of calls exceeded!" << std::endl;
        exit(0);
    }

    std::cerr << "Weigh called with:" << std::endl;
    std::cerr << "A = {";
    for (int i = 0; i < a.size(); ++ i)
    {
        std::cerr << a[i];
        if (i + 1 != a.size()) std::cerr << ", ";
    }
    std::cerr << "}" << std::endl;
    std::cerr << "B = {";
    for (int i = 0; i < b.size(); ++ i)
    {
        std::cerr << b[i];
        if (i + 1 != b.size()) std::cerr << ", ";
    }
    std::cerr << "}" << std::endl;

    if (a.size() != b.size())
    {
        std::cerr << "Different set sizes!" << std::endl;
        std::cerr << "A contains " << a.size() << "coins while B contains " << b.size() << "coins." << std::endl;
        exit(0);
    }

    int heavyA = 0, heavyB = 0;
    for (int i = 0; i < a.size(); ++ i)
    {
        if (a[i] < 0 or a[i] >= _heavyOrLight.size())
        {
            std::cerr << "Invalid coin index!" << std::endl;
            std::cerr << a[i] << " is not a valid index of a coin." << std::endl;
            exit(0);
        }
        if (_used[a[i]])
        {
            std::cerr << "Repeated use of a coin!" << std::endl;
            std::cerr << "The coins with index " << a[i] << " is present more than once in the sets." << std::endl;
            exit(0);
        }
        _used[a[i]] = true;
        if (_heavyOrLight[a[i]]) heavyA++;
    }
    for (int i = 0; i < b.size(); ++ i)
    {
        if (b[i] < 0 or b[i] >= _heavyOrLight.size())
        {
            std::cerr << "Invalid coin index!" << std::endl;
            std::cerr << b[i] << " is not a valid index of a coin." << std::endl;
            exit(0);
        }
        if (_used[b[i]])
        {
            std::cerr << "Repeated use of a coin!" << std::endl;
            std::cerr << "The coins with index " << b[i] << " is present more than once in the sets." << std::endl;
            exit(0);
        }
        _used[b[i]] = true;
        if (_heavyOrLight[b[i]]) heavyB++;
    }

    for (int i = 0; i < a.size(); ++ i)
    {
        _used[a[i]] = false;
    }
    for (int i = 0; i < b.size(); ++ i)
    {
        _used[b[i]] = false;
    }

    if (heavyA < heavyB)
    {
        std::cerr << "B is heavier than A" << std::endl;
        return -1;
    }
    if (heavyA > heavyB)
    {
        std::cerr << "A is heavier than B" << std::endl;
        return +1;
    }
    std::cerr << "A and B are equally heavy" << std::endl;
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cerr.tie(0);

    int k, n, cnt = 0;
    std::cin >> k;
    n = 1 << k;
    for (int i = 0; i < n; ++ i)
    {
        int x;
        std::cin >> x;
        _heavyOrLight.push_back(x);
        cnt += x;
    }
    _used.resize(n);

    auto ans = solve(k);

    std::cerr << "Your function called weigh() " << _cnt_calls << " times" << std::endl;
    std::cerr << "According to your function:" << std::endl;
    std::cerr << "1) The number of heavy coins is " << ans.first << "." << std::endl;
    std::cerr << "2) The coin with index " << ans.second << " is heavy." << std::endl;

    bool correct = true;
    if (ans.first != cnt)
    {
        std::cerr << "The true count of heavy coins is " << cnt << std::endl;
        correct = false;
    }
    if (ans.second < 0 or ans.second >= n)
    {
        std::cerr << ans.second << " is not a valid index of a coin!" << std::endl;
        correct = false;
    }
    else if (!_heavyOrLight[ans.second])
    {
        std::cerr << "The coin with index " << ans.second << " is not heavy!" << std::endl;
        correct = false;
    }

    if (correct) std::cerr << "Correct answer!" << std::endl;
    else std::cerr << "Wrong answer!" << std::endl;

    return 0;
}
