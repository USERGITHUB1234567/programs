#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = x; i <= y; ++ i)
#define ftd(i, x, y) for(int i = x; i >= y; -- i)
#define pb push_back
#define fi first
#define se second
#define pi pair <int , int>
using namespace std;

typedef long long ll;

const int N = 2e6 + 2;
const ll oo = 1e15;

int n, q, s, tree[N], cnt;

ll d[N];

vector <pi> a[N];

priority_queue <pi, vector <pi>, greater <pi>> pq;

struct info
{
	int t, u, l, r, w;
};

vector <info> qu;

void lph()
{
	freopen("legacy.inp", "r", stdin);
	freopen("legacy.out", "w", stdout);
}

void inp()
{
	cin >> n >> q >> s;
	while(q --)
	{
		int t, u, l, r, w;
		cin >> t >> u;
		if(t == 1)
		{
			cin >> l >> w;
			qu.pb({t, u, l, l, w});
		}
		else
		{
			cin >> l >> r >> w;
			qu.pb({t, u, l, r, w});
		}
	}
}

void pussy(int u, int v, int w)
{
	a[u].pb({v, w});
}

void build(int node, int l, int r)
{
	if(l == r)
	{
		tree[node] = l;
		return;
	}
	tree[node] = ++ cnt;
	int p1 = node * 2, p2 = p1 + 1, c = (l + r) >> 1;
	build(p1, l, c);
	build(p2, c + 1, r);

	pussy(tree[node], tree[p1], 0);
	pussy(tree[node], tree[p2], 0);
//	pussy(tree[p1], tree[node], 0);
//	pussy(tree[p2], tree[node], 0);

}

void add_xuoi(int node, int l, int r, int u, int i, int j, int w)
{
	if(i > r || j < l)
		return;
	if(l == i && j == r)
	{
		pussy(u, tree[node], w);
		return;
	}
	int p1 = node * 2, p2 = p1 + 1, c = (l + r) >> 1;
	add_xuoi(p1, l, c, u, i, min(c, j), w);
	add_xuoi(p2, c + 1, r, u, max(c + 1, i), j, w);
}

void add_ngc(int node, int l, int r, int u, int i, int j, int w)
{
	if(i > r || j < l)
		return;
	if(l == i && j == r)
	{
		pussy(tree[node], u, w);
		return;
	}
	int p1 = node * 2, p2 = p1 + 1, c = (l + r) >> 1;
	add_ngc(p1, l, c, i, u, min(c, j), w);
	add_ngc(p2, c + 1, r, u, max(c + 1, i), j, w);
}

void dijiktra(int s)
{
	fti(i, 1, cnt)
		d[i] = oo;
	d[s] = 0;
	pq.push({0, s});
	while(pq.size())
	{
		auto [c, u] = pq.top();
		pq.pop();
		if(c != d[u])
			continue;
		for(auto [v, w]: a[u])
		{
			if(d[v] > 1ll * w + c)
			{
				d[v] = 1ll * w + c;
				pq.push({d[v], v});
			}
		}
	}
}

void sub1()
{
	for(auto [t, u, l, r, w]: qu)
	{
		if(t == 3)
			fti(i, l, r)
				pussy(i, u, w);
		else
			fti(i, l, r)
				pussy(u, i, w);
	}
	dijiktra(s);
	fti(i, 1, n)
		cout << (d[i] == oo ? -1 : d[i]) << " ";
}

void sub2()
{
	build(1, 1, n);
	for(auto [t, u, l, r, w]: qu)
	{
		if(t == 3){
			add_ngc(1, 1, n, u, l, r, w);
			if(l <=s && s <= r)
				a[s].pb({u, w});
		}
		else
			add_xuoi(1, 1, n, u, l, r, w);
	}
	dijiktra(s);
	fti(i, 1, n)
		cout << (d[i] == oo ? -1 : d[i]) << " ";
}

void proc()
{
	cnt = n;
	if(n <= 2e3 && q <= 2e3)
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
/*
3 5 1
2 3 2 3 17
2 3 2 2 16
2 2 2 3 3
2 3 1 1 12
1 3 3 17
*/
