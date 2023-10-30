#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000005;
#define ls t[u].lson
#define rs t[u].rson
struct Node {
  int lson, rson, size;
  char ch;
  int p;
  int count[26], next[22], match[22];
} t[maxn];
mt19937 rng;
char p[22];
int root, cnt, pl, fail[22];

void pushup(int u) {
  if (u == 0) {
    t[u].size = 0;
    return;
  }
  t[u].size = t[ls].size + t[rs].size + 1;
  { for (int i = 0; i < 26; ++i) t[u].count[i] = t[ls].count[i] + t[rs].count[i];
    ++t[u].count[t[u].ch - 'a']; }
  for (int i = 0; i < pl; ++i) {
    int j = t[ls].next[i], m = 0;
    while (j != 0 && p[j + 1] != t[u].ch) j = fail[j];
    if (p[j + 1] == t[u].ch) ++j;
    if (j == pl) ++m, j = fail[j];
    t[u].next[i] = t[rs].next[j];
    t[u].match[i] = t[ls].match[i] + m + t[rs].match[j];
  }
}
void split(int u, int k, int &x, int &y) {
  if (!u) { x = y = 0; return; }
  if (k <= t[ls].size) {
    y = u;
    split(ls, k, x, ls);
  } else {
    x = u;
    split(rs, k - t[ls].size - 1, rs, y);
  }
  pushup(u);
}
int merge(int u, int v) {
  if (!u || !v) return u + v;
  if (t[u].p < t[v].p) {
    t[u].rson = merge(t[u].rson, v);
    pushup(u); return u;
  } else {
    t[v].lson = merge(u, t[v].lson);
    pushup(v); return v;
  }
}
int newnode(char ch) {
  t[++cnt].ch = ch;
  t[cnt].p = rng();
  pushup(cnt);
  return cnt;
}
int build(int l, int r, const string &s) {
  if (l > r) return 0;
  int mid = l + r >> 1, u = newnode(s[mid]);
  t[u].lson = build(l, mid - 1, s);
  t[u].rson = build(mid + 1, r, s);
  pushup(u);
  return u;
}

// void print(int u) {
//   if (!u) return;
//   clog << u << ' ' << ls << ' ' << rs << ' ' << t[u].size << ' ' << t[u].count[0] << endl;
//   print(ls);
//   cout << t[u].ch;
//   print(rs);
// }

int n;
int main() {
  //freopen("edit.in", "r", stdin);
  //freopen("edit.out", "w", stdout);
  rng.seed(random_device{}());
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> (p + 1);
  pl = std::strlen(p + 1);
  for (int i = 2, j = 0; i <= pl; ++i) {
    while (j != 0 && p[j + 1] != p[i]) j = fail[j];
    if (p[j + 1] == p[i]) ++j;
    fail[i] = j;
  }
  for (int i = 0; i < pl; ++i) t[0].next[i] = i;
  while (n--) {
    string op, s;
    char ch;
    int l, r, x, y, z;
    cin >> op;
    if (op == "Insert") {
      cin >> l >> s;
      split(root, l, x, y);
      root = merge(merge(x, build(0, s.length() - 1, s)), y);
    } else if (op == "Delete") {
      cin >> l >> r;
      split(root, r, x, z); split(x, l - 1, x, y);
      root = merge(x, z);
    } else if (op == "Replace") {
      cin >> l >> r >> s;
      split(root, r, x, z); split(x, l - 1, x, y);
      root = merge(merge(x, build(0, s.length() - 1, s)), z);
    } else if (op == "Count") {
      cin >> l >> r >> ch;
      split(root, r, x, z); split(x, l - 1, x, y);
      cout << t[y].count[ch - 'a'] << '\n';
      root = merge(merge(x, y), z);
    } else if (op == "Search") {
      cin >> l >> r;
      split(root, r, x, z); split(x, l - 1, x, y);
      cout << t[y].match[0] << '\n';
      root = merge(merge(x, y), z);
    } // else print(root), cout << '\n';
  }
  cout.flush();
  return 0;
}