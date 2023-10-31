#include <bits/stdc++.h>

inline long long netflow(int s, int t, std::vector<std::vector<long long>> cap) {
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    int n = (int)cap.size();
    std::vector<int> pre(n), cur(n, 0), dep(n, 0), num(n, 0);
    std::vector<long long> f(num[0] = n);
    int u = s;
    long long flow = INF, maxflow = 0;

    while (dep[u] < n) {
        f[u] = flow;
        bool ok = false;

        for (int v = cur[u]; v < n; v++) {
            if (!cap[u][v] || dep[u] != dep[v] + 1)
                continue;

            ok = true, pre[v] = u, cur[u] = v, flow = std::min(cap[u][v], flow), u = v;

            if (u == t) {
                maxflow += flow;

                while (u != s) {
                    cap[pre[u]][u] -= flow;
                    cap[u][pre[u]] += flow;
                    u = pre[u];
                }

                flow = INF;
            }

            break;
        }

        if (ok)
            continue;

        if (--num[dep[u]] == 0)
            break;

        int c = -1;

        for (int v = 0; v < n; v++)
            if (cap[u][v] && (c == -1 || dep[v] < dep[c]))
                c = v;

        cur[u] = c, num[dep[u] = (~c ? dep[c] : n) + 1]++;

        if (u != s)
            u = pre[u], flow = f[u];
    }

    return maxflow;
}

int main() {
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    std::vector<std::vector<long long>> cap(n, std::vector<long long>(n));

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        cap[u - 1][v - 1] += w;
    }

    printf("%lld\n", netflow(s - 1, t - 1, cap));
    return 0;
}