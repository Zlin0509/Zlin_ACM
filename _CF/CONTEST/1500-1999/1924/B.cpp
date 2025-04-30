#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 300005

int n, m, q, X[MAXN], V[MAXN], opt[MAXN], qx[MAXN], qv[MAXN], ql[MAXN], qr[MAXN];
int tr[MAXN + 5], Ans[MAXN];

inline void add(int x, int k) { for (; x <= MAXN; x += x & -x) tr[x] += k; }

inline int sum(int x)
{
	int ret = 0;
	for (; x; x -= x & -x) ret += tr[x];
	return ret;
}

struct node
{
	int l, r, id, cost;
	inline bool operator <(node B) const { return r < B.r; }
};

inline int Sp(int x) { return x * (x + 1) / 2; }

signed main()
{
	scanf("%lld%lld%lld", &n, &m, &q);
	multiset<node> S;
	S.insert(node{1, n, 0, 0});
	for (int i = 1; i <= m; i++) scanf("%lld", &X[i]);
	for (int i = 1; i <= m; i++) scanf("%lld", &V[X[i]]);
	for (int i = 1; i <= m; i++)
	{
		if (X[i] == 1 || X[i] == n) continue;
		set<node>::iterator it = S.lower_bound(node{X[i], X[i], 0, 0});
		S.insert(node{it->l, X[i], 0, 0});
		S.insert(node{X[i], it->r, 0, 0});
		S.erase(it);
	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%lld", &opt[i]);
		if (opt[i] == 1)
		{
			scanf("%lld%lld", &qx[i], &qv[i]);
			V[qx[i]] = qv[i];
			set<node>::iterator it = S.lower_bound(node{qx[i], qx[i], 0, 0});
			S.insert(node{it->l, qx[i], 0, 0});
			S.insert(node{qx[i], it->r, 0, 0});
			S.erase(it);
		}
		else scanf("%lld%lld", &ql[i], &qr[i]);
	}
	int cnt = 0;
	multiset<node> S2;
	for (node N : S)
	{
		int l = N.l, r = N.r;
		N.id = ++cnt, N.cost = V[l] * Sp(r - l - 1);
		add(N.id, N.cost);
		S2.insert(N);
	}
	S = S2;
	for (int i = q; i >= 1; i--)
	{
		if (opt[i] == 2)
		{
			int L = ql[i], R = qr[i];
			multiset<node>::iterator it2 = S.lower_bound(node{R, R, 0, 0});
			multiset<node>::iterator it = S.lower_bound(node{L, L, 0, 0});
			if (it->l == it2->l)
			{
				if (L == it->l) L++;
				Ans[i] = V[it->l] * (Sp(R - L) + (R - L + 1) * (it->r - R));
			}
			else
			{
				int idl = it->id, idr = it2->id;
				Ans[i] = sum(idr - 1) - sum(idl);
				int l1 = it->l, l2 = it2->l, r1 = it->r, r2 = it2->r;
				Ans[i] += V[l2] * (Sp(R - l2 - 1) + (R - l2) * (r2 - R));
				if (L == l1) L++;
				Ans[i] += V[l1] * Sp(r1 - L);
			}
		}
		else
		{
			int x = qx[i];
			multiset<node>::iterator it = S.lower_bound(node{x, x, 0, 0}), it2 = it;
			it2++;
			int idl = it->id, idr = it2->id;
			add(idl, -(it->cost)), add(idr, -(it2->cost));
			node New;
			New.l = it->l, New.r = it2->r, New.id = idl, New.cost = V[New.l] * Sp(New.r - New.l - 1);
			add(New.id, New.cost);
			S.erase(it), S.erase(it2);
			S.insert(New);
		}
	}
	for (int i = 1; i <= q; i++) if (opt[i] == 2) printf("%lld\n", Ans[i]);
	return 0;
}
