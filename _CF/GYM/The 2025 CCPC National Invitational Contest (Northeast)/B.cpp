//
// Created by 朱 on 25-5-30.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr int N = 1e6 + 10;

priority_queue<pii> pq;
set<int> have;

int n, k;
int a[N];

inline void Zlin() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		have.insert(i);
	}
	for(int i = 1; i < n; i++) {
		if(a[i] < a[i + 1]) {
			pq.push({1, i});
		} else {
			pq.push({0, i});
		}
	}
	pq.push({0, n});
	while(k) {
		auto [op, id] = pq.top();
		pq.pop();
		if(have.find(id) == have.end()) continue;
		if(op) {
			--k;
			have.erase(have.find(id));
			auto rx = have.lower_bound(id);
			if(rx != have.end()) {
				auto lx = prev(rx);
				if(a[*lx] < a[*rx]) pq.push({1, *lx});
			}
		} else {
			while(k >= 2 && have.size() >= 2) {
				have.erase(next(have.begin()));
				k -= 2;
			}
			if(k && have.size() >= 2) {
				if(a[1] < a[*next(have.begin())]) {
					have.erase(next(have.begin()));
					have.insert(1);
				} else {
					swap(a[*have.begin()], a[*next(have.begin())]);
				}
			}
			k = 0;
		}
	}
	cout << have.size() << endl;
	for(int it: have) cout << a[it] << ' ';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int ttt = 1;
	while(ttt--) Zlin();
	return 0;
}