/*** 
 * @Author: ltt
 * @Date: 2023-08-11 16:32:42
 * @LastEditors: ltt
 * @LastEditTime: 2023-08-15 07:56:32
 * @FilePath: std.cpp
*/
#include <bits/stdc++.h>
#define MAXN 500010

using namespace std;
int n, m, tot, ti, dfn;
int head[MAXN], to[MAXN<<1], nex[MAXN<<1], euler[30][MAXN<<1], dep[MAXN], pos[MAXN];
int lg[MAXN<<1];
// euler[i][j]: ���� [j, j + 2^i) �� dep ��С�Ľڵ���

void add_edge(int u, int v) {
	to[++tot] = v;
	nex[tot] = head[u];
	head[u] = tot;
}

void dfs(int u, int fa = 0, int deep = 1) {
	euler[0][++dfn] = u;
	pos[u] = dfn;
	dep[u] = deep;
	for (int i=head[u]; i; i=nex[i]) {
		int v = to[i];
		if (fa == v) continue;
		dfs(v, u, deep + 1);
		euler[0][++dfn] = u;
	}
}

void init() {
	for (int i=2; i<= dfn+1; ++i) lg[i] = lg[i >> 1] + 1;
	for (int i=1; i <= lg[dfn]; ++i) {
		for (int j = 1; j + (1<<i) - 1 <= dfn; ++j) {
			if (dep[euler[i-1][j]] < dep[euler[i-1][j + (1<< i-1)]])
				euler[i][j] = euler[i-1][j];
			else
				euler[i][j] = euler[i-1][j + (1<< i-1)];
		}
	}
}

int query(int u, int v) {
	int l = pos[u], r = pos[v];
	if (l > r) swap(l, r);
	int k = lg[r - l + 1];
	return dep[euler[k][l]] < dep[euler[k][r - (1<<k) + 1]] ? euler[k][l] : euler[k][r - (1<<k) + 1];
}

int main()
{
	 freopen("lca.in", "r", stdin);
	 freopen("lca.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i=1, u, v; i<n; ++i) {
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs(1);
	init();
	for (int i=1, u, v; i<=m; ++i) {
		scanf("%d%d", &u, &v);
		printf("%d\n", query(u, v));
	}
	return 0;

}
