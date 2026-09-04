#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = x; i <= y; ++ i)
#define ftd(i, x, y) for(int i = x; i >= y; -- i)
#define pb push_back
#define fi first
#define se second
#define pi pair <int , int>
using namespace std;

typedef long long ll;

const int N = 1e6 + 2;
const ll oo = 1e9;

int n, s, t[N], f[N], o[N];

int s1[N], s2[N];

pi dp[N];

vector <int> a[N];

void lph()
{
	freopen("batch.inp", "r", stdin);
	freopen("batch.out", "w", stdout);
}

void inp()
{
	cin >> n >> s;
	fti(i, 1, n)
	{
		cin >> t[i] >> f[i];
		s1[i] = s1[i - 1] + t[i];
		s2[i] = s2[i - 1] + f[i];
	}
}

void sub1()
{
	int nmask = (1 << n);
	ll res = oo;
	fti(mask, 0, nmask - 1)
	{
		int prv = 0, m = 0;
		fti(i, 1, n)
		{
			if(mask >> (i - 1) & 1)
			{
				++ m;
				fti(j, prv + 1, i)
					a[m].pb(j);
				prv = i;
			}
		}
		if(!(mask >> (n - 1) & 1))
		{
			++ m;
			fti(j, prv + 1, n)
				a[m].pb(j);
		}
		ll cur = 0;
		fti(i, 1, m)
		{
			ll sum = 0;
			for(int j: a[i])
				sum += t[j];
			cur += sum + s;
			for(int j: a[i])
				o[j] = cur;
		}
		ll tmp = 0;
		fti(i, 1, n)
		{
//			cout << o[i] << " ";
			tmp += o[i] * f[i];
		}
//		cout << '\n';
		res = min(res, tmp);
		fti(i, 1, n)
		{
			if(a[i].size())
				a[i].clear();
			o[i] = 0;
		}
	}
	cout << res;
}

void sub2()
{
	fti(i, 1, n)
		dp[i] = {oo, 0};
//	dp[0] = {0, 0};
	dp[1] = {(s + s1[1]) * (s2[1]), (s + s1[1])};
	fti(i, 1, n)
	{
		fti(j, 1, i - 1)
		{
			ll cost = (dp[j].se + s + s1[i] - s1[j]) * (s2[i] - s2[j]);
			if(dp[i].fi > dp[j].fi + cost)
			{
				dp[i].fi = dp[j].fi + cost;
				dp[i].se = (dp[j].se + s + s1[i] - s1[j]);
			}
		}
	}
	cout << dp[n].fi;
}

void proc()
{
	if(n <= 10)
		sub1();
	else
		sub2();
}

int main()
{
	lph();
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	inp();
	proc();
	return 0;
}
