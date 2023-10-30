struct Query {
  int id, k;  // 这个询问的编号, 这个询问的k
};

int ans[N];        // ans[i] 表示编号为i的询问的答案
int check(int x);  // 返回原数列中小于等于x的数的个数

void solve(int l, int r, vector<Query> q)
// 请补全这个函数
{
  int m = (l + r) / 2;
  vector<Query> q1, q2;  // 将被划到左侧的询问和右侧的询问
  if (l == r) {
    // ...
    return;
  }
  // ...
  solve(l, m, q1), solve(m + 1, r, q2);
  return;
}

