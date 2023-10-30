/*** 
 * @Author: ltt
 * @Date: 2023-08-10 13:50:53
 * @LastEditors: ltt
 * @LastEditTime: 2023-08-10 14:17:49
 * @FilePath: std.cpp
*/
#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;
int tot = 0, n;
int head[MAXN], to[MAXN<<1], nex[MAXN<<1], weight[MAXN<<1];

void add_edge(int u, int v, int w) {
	to[++tot] = v;
	weight[tot] = w;
	nex[tot] = head[u];
	head[u] = tot;
}

int xi, max_dis = 0;
void dfs(int u, int dis = 0, int fa = 0) {
	if (max_dis < dis) {
		max_dis = dis;
		xi = u;
	}
	for (int i=head[u]; i; i=nex[i]) {
		int v = to[i];
		if (fa == v) continue;
		dfs(v, dis + weight[i], u);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1, u, v, w;i<n;++i) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	dfs(1);
	dfs(xi);
	printf("%d", max_dis);
	return 0;
}