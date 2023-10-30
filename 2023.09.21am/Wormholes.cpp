#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int T, n, m, W, dis[505][505];
inline int read() {
	register int x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + c - '0';c = getchar();}
	return x;
}
bool check() {
	for (register int k = 1; k <= n; k++)
		for (register int i = 1; i <= n; i++) {
			for (register int j = 1; j <= n; j++) {
				int res = dis[i][k] + dis[k][j];
				if (dis[i][j] > res) dis[i][j] = res;
			}
			if (dis[i][i] < 0) return 1;
		}
	return 0;
}
inline void _File(){
	freopen("Wormholes.in","r",stdin);
	freopen("Wormholes.out","w",stdout);
}
int main() {
	_File();
	T = read();
	while (T--) {
		n = read(), m = read(), W = read();
		for (register int i = 1; i <= n; i++)
			for (register int j = 1; j <= n; j++)
				dis[i][j] = INF;
		for (int i = 1; i <= m; i++) {
			int u = read(), v = read(), w = read();
			if (dis[u][v] > w) dis[u][v] = dis[v][u] = w;
		}
		for (int i = 1; i <= W; i++) {
			int u = read(), v = read(), w = read();
			dis[u][v] = -w;
		}
		if (check()) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
