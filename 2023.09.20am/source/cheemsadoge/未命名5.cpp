#include <cstdio>
#include <algorithm>
#define N 310
#define INF 0x3f3f3f3f

int n, a[N], w[N][N];
int tot, cnt, ans;

struct T {
    int u, v, w;
    bool operator<(const T &x) const {
        return w < x.w;
    }
} e[N * N];

int fa[N];

int get(int x) {
    return x == fa[x] ? x : fa[x] = get(fa[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        scanf("%d", a + i);
        e[++tot].u = 0;
        e[tot].v = i;
        e[tot].w = a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &w[i][j]);
            if (j > i) {
                e[++tot].u = i;
                e[tot].v = j;
                e[tot].w = w[i][j];
            }
        }
    }
    std::sort(e + 1, e + tot + 1);
    for (int i = 1; i <= tot && cnt < n; i++) {
        int u = get(e[i].u), v = get(e[i].v);
        if (u == v) continue;
        cnt++;
        fa[u] = v;
        ans += e[i].w;
    }
    printf("%d\n", ans);
    return 0;
}