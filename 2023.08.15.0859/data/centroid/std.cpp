/*** 
 * @Author: ltt
 * @Date: 2023-08-10 13:50:53
 * @LastEditors: ltt
 * @LastEditTime: 2023-08-10 14:25:31
 * @FilePath: std.cpp
*/
#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;
int tot = 0, n;
int head[MAXN], to[MAXN<<1], nex[MAXN<<1], siz[MAXN], centroid[2];

void add_edge(int u, int v) {
	to[++tot] = v;
	nex[tot] = head[u];
	head[u] = tot;
}

void dfs(int u, int fa = 0) {
	siz[u] = 1;
	int count = 0;
	for (int i=head[u]; i; i=nex[i]) {
		int v = to[i];
		if (fa == v) continue;
		dfs(v, u);
		count = max(count, siz[v]);
		siz[u] += siz[v];
	}
	count = max(count, n - siz[u]);
	if (count <= n / 2) {
		centroid[centroid[0] != 0] = u;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1, u, v;i<n;++i) {
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs(1);
	if (centroid[1]) {
		if (centroid[0] > centroid[1]) swap(centroid[0], centroid[1]);
		printf("%d %d", centroid[0], centroid[1]);
	} else printf("%d", centroid[0]);
	return 0;
}