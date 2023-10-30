#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge {
    int next, v, w;
} e[200001];
int n, m, s, cnt;
int h[2005], dis[2005], tot[2005];
bool vis[2005];
void add(int u, int v, double w) {
    e[++cnt].next = h[u];
    h[u] = cnt;
    e[cnt].v = v;
    e[cnt].w = w;
}
bool SPFA(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(tot, 0, sizeof(tot));
    queue<int>q;
    vis[s] = 1;
    dis[s] = 0;
    tot[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        vis[p] = 0;
        for (int i = h[p]; i; i = e[i].next) {
            int v = e[i].v, d = e[i].w;
            if (dis[v] > dis[p] + d) {
                dis[v] = dis[p] + d;
                tot[v] = tot[p] + 1;
                if (tot[v] > n + 1)
                    return 1;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return 0;
}
signed main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        add(n + 1, i, 0);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    if (SPFA(n + 1))
        cout << -1;
    else {
        bool nus = SPFA(s);
        for (int i = 1; i <= n; i++) {
            if (dis[i] == dis[0])
                cout << "NoPath" << endl;
            else
                cout << dis[i] << endl;
        }
    }

    return 0;
}
