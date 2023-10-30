#define Tokisaki return
#define Kurumi 0;
#include <bits/stdc++.h>
#define LL long long
#define PB emplace_back
using namespace std;
const int N = 100010, MAXN = 3276800, INF = 2e9;
namespace IO {
#define getchar()(p1==p2&&(p2=(p1=B)+fread(B,1,1<<16,stdin),p1==p2)?EOF:*p1++)
char B[1 << 16], *p1 = B, *p2 = B;
template<typename Tp>void read(Tp &x) {
    x = 0;
    bool f = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        f |= ch == '-', ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
    if (f)
        x = -x;
} template<typename types, typename...Args>void read(types &x, Args &...args) {
    read(x), read(args...);
} template<typename Tp>void write(Tp x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    Tp k = x / 10;
    if (k)
        write(k);
    putchar(x - (k << 3) - (k << 1) + '0');
}
};
int n, Q;
int w[N], c[N];
int e[N << 1], ne[N << 1], h[N], idx;
int dep[N], fa[N], sz[N], hson[N], top[N], dfn[N], tot, rk[N];
struct Node {
    int ls, rs;
    LL sum;
    int mx;
} tr[MAXN];
int cnt, rt[N];
void pushup(int u) {
    tr[u].sum = tr[tr[u].ls].sum + tr[tr[u].rs].sum;
    tr[u].mx = max(tr[tr[u].ls].mx, tr[tr[u].rs].mx);
}
void insert(int pos, int l, int r, int &root) {
    if (!root)
        root = ++cnt;
    if (l == r) {
        tr[root].mx = tr[root].sum = w[dfn[pos]];
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        insert(pos, l, mid, tr[root].ls);
    else
        insert(pos, mid + 1, r, tr[root].rs);
    pushup(root);
}
void Remove(int pos, int l, int r, int u) {
    if (l == r) {
        tr[u].sum = tr[u].mx = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        Remove(pos, l, mid, tr[u].ls);
    else
        Remove(pos, mid + 1, r, tr[u].rs);
    pushup(u);
}
void modify(int pos, int l, int r, int u) {
    if (l == r) {
        tr[u].sum = tr[u].mx = w[dfn[pos]];
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        modify(pos, l, mid, tr[u].ls);
    else
        modify(pos, mid + 1, r, tr[u].rs);
    pushup(u);
}
LL query_sum(int u, int l, int r, int L, int R) {
    if (L <= l && r <= R)
        return tr[u].sum;
    int mid = (l + r) >> 1;
    LL res = 0;
    if (L <= mid)
        res += query_sum(tr[u].ls, l, mid, L, R);
    if (R > mid)
        res += query_sum(tr[u].rs, mid + 1, r, L, R);
    return res;
}
int query_mx(int u, int l, int r, int L, int R) {
    if (L <= l && r <= R)
        return tr[u].mx;
    int mid = (l + r) >> 1;
    int res = -INF;
    if (L <= mid)
        res = max(res, query_mx(tr[u].ls, l, mid, L, R));
    if (R > mid)
        res = max(res, query_mx(tr[u].rs, mid + 1, r, L, R));
    return res;
}
void add_edge(int u, int v) {
    e[idx] = v;
    ne[idx] = h[u];
    h[u] = idx++;
}
void dfs1(int u) {
    hson[u] = -1;
    sz[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        if (!dep[e[i]]) {
            dep[e[i]] = dep[u] + 1;
            fa[e[i]] = u;
            dfs1(e[i]);
            sz[u] += sz[e[i]];

            if (hson[u] == -1 || sz[hson[u]] < sz[e[i]])
                hson[u] = e[i];
        }
    }
}
void dfs2(int u, int t) {
    top[u] = t;
    dfn[++tot] = u;
    rk[u] = tot;
    if (hson[u] == -1)
        return;
    dfs2(hson[u], t);
    for (int i = h[u]; ~i; i = ne[i]) {
        if (e[i] == hson[u] || e[i] == fa[u])
            continue;
        dfs2(e[i], e[i]);
    }
}
LL query_sum(int x, int y) {
    LL res = 0;
    int col = c[x];
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        res += query_sum(rt[col], 1, n, rk[top[x]], rk[x]);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    res += query_sum(rt[col], 1, n, rk[x], rk[y]);
    return res;
}
int query_mx(int x, int y) {
    int res = -INF;
    int col = c[x];
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);

        res = max(res, query_mx(rt[col], 1, n, rk[top[x]], rk[x]));
        x = fa[top[x]];
    }

    if (dep[x] > dep[y])
        swap(x, y);

    res = max(res, query_mx(rt[col], 1, n, rk[x], rk[y]));
    return res;
}
int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &Q);

    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &w[i], &c[i]);

    for (int i = 1, u, v; i <= n - 1; ++i) {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    dep[1] = 1;
    dfs1(1);
    dfs2(1, 1);

    for (int i = 1; i <= n; ++i)
        insert(rk[i], 1, n, rt[c[i]]);

    char op[5];
    int x, y;

    while (Q--) {
        scanf("%s%d%d", op, &x, &y);

        if (op[1] == 'C') {
            Remove(rk[x], 1, n, rt[c[x]]);
            c[x] = y;
            insert(rk[x], 1, n, rt[c[x]]);
        } else if (op[1] == 'W') {
            w[x] = y;
            modify(rk[x], 1, n, rt[c[x]]);
        } else if (op[1] == 'S') {
            IO::write(query_sum(x, y));
            putchar('\n');
        } else {
            IO::write(query_mx(x, y));
            putchar('\n');
        }
    }

    Tokisaki Kurumi
}
