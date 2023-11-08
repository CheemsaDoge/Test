/*** 
 * @Author: CheemsaDoge
 * @Date: 2023-11-08 09:37:51
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-08 11:37:54
 * @FilePath: \TEST\2023.11.08\fac.cpp
 * @Forgive me.
 * @Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -f; c = getchar();}
	while (c >= '0' && c <= '9') {x = (x << 3) + (x << 1) + (c ^ 48); c = getchar();}
	return x * f;
}
const int N = 4e6 + 10, M = 1e7 + 10;
int n;
int ct, pri[M], id[M], mn[M]; bool vis[M]; 
inline void seive() {
	for (int i = 2; i < M; ++ i) {
		if (!vis[i]) pri[++ ct] = i, mn[i] = i;
		for (int j = 1; j <= ct && i * pri[j] < M; ++ j) {
			vis[i * pri[j]] = 1; mn[i * pri[j]] = pri[j];
			if (i % pri[j] == 0) break;
		}
	} ct = 0;
	for (int i = 2; i < M; ++ i) if (vis[i] && !vis[i/mn[i]]) id[i] = ++ ct;
}

int tot = 1, hd[N], nxt[M], ver[M];
inline void add_edge(int u, int v) {ver[++tot] = v; nxt[tot] = hd[u]; hd[u] = tot;}
int f[N], g[N];
inline int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
inline void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	f[x] = y; g[y] += g[x]; 
}
int tim, dfn[N], low[N], siz[N];
int top, stc[N];
inline void init() {
	for (int i = 1; i <= n+ct; ++ i) f[i] = i, g[i] = (i <= n);
	memset(dfn, 0, sizeof dfn); tim = top = 0;
	tot = 1; memset(hd, 0, sizeof hd);
}
int mx, se, mxp;
inline void upd(int v, int x) {
	if (v > mx) se = mx, mx = v, mxp = x;
	else if (v > se) se = v;
}
int ans, all;
inline void tarjan(int u, int eid) {
	dfn[u] = low[u] = ++ tim; stc[++ top] = u; siz[u] = 0;
	int ret = 0, flg = 0;
	for (int i = hd[u]; i; i = nxt[i]) {
		if (i == (eid ^ 1)) continue;
		int v = ver[i]; 
		if (!dfn[v]) {
			tarjan(v, i); low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) flg ++;
			if (low[v] > dfn[u]) top --, ret = max(ret, siz[v]), siz[u] += siz[v];
			else if (low[v] == dfn[u]) {
				int t, s = 0;
				do {
					t = stc[top --];
					siz[u] += siz[t]; s += siz[t];
				} while(t != v);
				ret = max(ret, s);
			} 
		} else low[u] = min(low[u], dfn[v]);
	} if (u <= n) {
		siz[u] ++;
		if ((eid && flg) || (!eid && flg > 1)) ans = min(ans, max(ret, all - siz[u]));
		else ans = min(ans, all - 1); 
	}
}
inline void solve() {
	n = read(); init();
	for (int i = 1, x; i <= n; ++ i) {
		int p[15] = {0}, c[15] = {0};
		x = read();
		while (x > 1) {
			int w = mn[x];
			p[++p[0]] = w;
			while (x % w == 0) c[p[0]] ++, x /= w;
		}
		for (int j = 1; j <= p[0]; ++ j)
			for (int k = j + (c[j] <= 1); k <= p[0]; ++ k)
				if (1ll * p[j] * p[k] < M) {
					int v = id[p[j] * p[k]] + n;
					add_edge(i, v); add_edge(v, i);
					merge(i, v);
				}
	}
	mx=0,se=0,mxp=0;
	for (int i = 1; i <= ct + n; ++ i) {
		if (f[i] != i || !g[i]) continue;
		upd(g[i], i);
	} ans = all = mx; tarjan(mxp, 0); 
	printf("%d\n", max(ans, se));
}

int main () {
	freopen("fac.in", "r", stdin);
	freopen("fac.out", "w", stdout);
	seive();
	int T = read(); while (T --) solve();
	return 0;
}
