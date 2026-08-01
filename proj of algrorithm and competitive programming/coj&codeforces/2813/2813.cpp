/*#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int dp[305][305][305];
char a[305][305];
string s;
const int di[4]={-1,0,0,-1},dj[4]{0,-1,-1,0};
int m,n,sx,sy;
void sub2()
{
    memset(dp,INT_MAX,sizeof(dp));
    cin >> m >> n >> sx >> sy >> s;
    sx--;
    sy--;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) cin >> a[i][j];
    }
    dp[sx][sy][0]=0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            for(int k=1; k<=s.size(); k++) {
                for(int r=0; r<m; r++) {
                    for(int c=0; c<n; c++) {
                        if(s[k-1]==a[r][c])
                            dp[i][j][k]=min(dp[r][c][k], dp[r][c][k-1]+abs(i-r)+abs(j-c));
                    }
                }
            }
        }
    }
    int ans=INT_MAX;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            ans=min(ans,dp[i][j][s.size()]);
        }
    }
    cout << ans;
}
int sub4()
{
    memset(dp,0x3f,sizeof(dp));
    cin >> m >> n >> sx >> sy;
    sx--;
    sy--;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) cin >> a[i][j];
    }
    cin >> s;
    dp[sx][sy][0]=0;
    queue<tuple<int,int,int>>pq;
    pq.push({sx,sy,0});
    int ans=1e9;
    while(!pq.empty()) {
        auto[i,j,k]=pq.front();
        pq.pop();
        if(k==s.size()) {
            cout << dp[i][j][k];
            break;
        }
        if(a[i][j]==s[k] and dp[i][j][k+1]>dp[i][j][k]) {
            dp[i][j][k+1]=dp[i][j][k];
            pq.push({i,j,k+1});
        }
        for(int d=0; d<4; d++) {
            int r=i+di[d],c=j+dj[d];
            if(r>=0 and r<m and c>=0 and c<n and dp[r][c][k]>dp[i][j][k]+1) {
                dp[r][c][k]=dp[i][j][k]+1;
                pq.push({r,c,k});
            }
        }
    }
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            ans=min(ans,dp[i][j][s.size()]);
        }
    }
    cout << ans;
}
int main()
{
    sub4();
}*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

const int INF = 1e9;
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

int dp[305][305][305];
char a[305][305];
string s;
int m, n, sx, sy;

void sub4() {
    cin >> m >> n >> sx >> sy;
    sx--; sy--;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cin >> s;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= s.size(); k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[sx][sy][0] = 0;
    queue<tuple<int, int, int>> pq;
    pq.push({sx, sy, 0});

    while (!pq.empty()) {
        auto [i, j, k] = pq.front();
        pq.pop();
        if (k == s.size()) {
            cout << dp[i][j][k];
            return;
        }
        if (a[i][j] == s[k] && dp[i][j][k + 1] > dp[i][j][k]) {
            dp[i][j][k + 1] = dp[i][j][k];
            pq.push({i, j, k + 1});
        }
        for (int d = 0; d < 4; d++) {
            int r = i + di[d], c = j + dj[d];
            if (r >= 0 && r < m && c >= 0 && c < n && dp[r][c][k] > dp[i][j][k] + 1) {
                dp[r][c][k] = dp[i][j][k] + 1;
                pq.push({r, c, k});
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[i][j][s.size()]);
        }
    }
    cout << ans;
}

int main() {
    sub4();
    return 0;
}
