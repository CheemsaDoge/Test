#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 4e6 + 5;
int cnt = 1, fir[N], nxt[M], to[M];
int s[M], top, bcc, low[N], dfn[N], idx, n, m;
vector<int> ans[N];
inline void tarjan(int u, int fa) {
	int son = 0;
	low[u] = dfn[u] = ++idx;
	s[++top] = u;
	for(int i = fir[u]; i; i = nxt[i]) {
		int v = to[i];
		if(!dfn[v]) {
			son++;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u]) {
				bcc++;
				while(s[top + 1] != v) ans[bcc].push_back(s[top--]);//将子树出栈
				ans[bcc].push_back(u);//把割点/树根也丢到点双里
			}
		} else if(v != fa) low[u] = min(low[u], dfn[v]);
	}
	if(fa == 0 && son == 0) ans[++bcc].push_back(u);//特判独立点
}
inline void add(int u, int v) {
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	fir[u] = cnt;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	for(int i = 1; i <= n; i++) {
		if(dfn[i]) continue;
		top = 0;
		tarjan(i, 0);
	}
	printf("%d\n", bcc);
	for(int i = 1; i <= bcc; i++) {
		printf("%d ", ans[i].size());
		for(int j : ans[i]) printf("%d ", j);
		printf("\n");
	}
	return 0;
}
