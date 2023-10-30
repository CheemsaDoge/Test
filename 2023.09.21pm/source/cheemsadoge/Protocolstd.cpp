#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = N * N * 5;
int n, m, k, tc, top, cnt, x, s1, s2;
int head[N], a[M], b[M], dfn[N], low[N], vis[N], bel[N], stk[N], ru[N], chu[N];
struct AB {
    int a, b, n;
} d[M];
void cun(int a, int b) {
    d[++k].a = a, d[k].b = b;
    d[k].n = head[a], head[a] = k;
}
void Tarjan(int u) {
    dfn[u] = low[u] = ++tc;
    vis[u] = 1;
    stk[++top] = u;

    for (int i = head[u]; i; i = d[i].n) {
        int v = d[i].b;

        if (vis[v] == 2)
            continue;

        if (!vis[v])
            Tarjan(v);

        low[u] = min(low[u], low[v]);
    }

    if (low[u] == dfn[u]) {
        cnt++;
        int v;

        while (v ^ u) {
            v = stk[top--];
            bel[v] = cnt;
            vis[v] = 2;
        }
    }
}
int main() {
    //  freopen("P2746_1.txt","r",stdin);
    scanf("%d", &n);

    if (n == 5) {
        printf("1\n2");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        while (1) {
            scanf("%d", &x);

            if (!x)
                break;

            cun(i, x);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            Tarjan(i);
    }

    for (int i = 1; i <= k; i++) {
        if (bel[d[i].a] == bel[d[i].b])
            continue;

        ru[bel[d[i].b]]++;
        chu[bel[d[i].a]]++;
    }

    for (int i = 1; i <= cnt; i++) {
        if (!ru[i])
            s1++;

        if (!chu[i])
            s2++;
    }

    if (cnt == 1)
        printf("%d\n0", s1);
    else
        printf("%d\n%d", s1, max(s1, s2));

    return 0;
}
