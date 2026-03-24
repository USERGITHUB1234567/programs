#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

bool sub[17];
string s[17];
int l[17], dp[100005][17], over[17][17];
int INF = 2000000000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && s[j].find(s[i]) != string::npos)
            {
                sub[i] = true;
                break;
            }

    int k = 0;
    for (int i = 0; i < n; i++)
        if (!sub[i])
            s[k++] = s[i];
    if (k == 0)
        n = 1;
    else
        n = k;

    for (int i = 0; i < n; i++)
        l[i] = s[i].size();


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int k = min(l[i], l[j]);
            while (k > 0 && s[i].substr(l[i] - k, k) != s[j].substr(0, k))
                k--;
            over[i][j] = k;
        }


    for (int cur = 1; cur <= (1 << n) - 1; cur++)
        for (int i = 0; i < n; i++)
            if ((cur & (1 << i)) != 0)
            {
                int pre = cur ^ (1 << i);
                if (pre == 0)
                    dp[cur][i] = l[i];
                else
                {
                    dp[cur][i] = INF;
                    for (int j = 0; j < n; j++)
                        if ((pre & (1 << j)) != 0)
                            dp[cur][i] = min(dp[cur][i], l[i] - over[i][j] + dp[pre][j]);
                }
            }


    for (int i = -1, cur = (1 << n) - 1; cur != 0; )
    {
        int min_len, best_j, best_len = INF;
        string min_str, best_str;
        for (int j = 0; j < n; j++)
            if (((cur >> j) & 1) != 0)
            {
                if (i == -1)
                {
                    min_len = dp[cur][j];
                    min_str = s[j];
                }
                else
                {
                    min_len = dp[cur][j] - over[i][j];
                    min_str = s[j].substr(over[i][j], l[j] - over[i][j]);
                }
                if ((min_len < best_len) || (min_len == best_len && min_str < best_str))
                {
                    best_j = j;
                    best_len = min_len;
                    best_str = min_str;
                }
            }
        cout << best_str;
        i = best_j;
        cur ^= (1 << best_j);
    }
    cout << '\n';
    return 0;
}
