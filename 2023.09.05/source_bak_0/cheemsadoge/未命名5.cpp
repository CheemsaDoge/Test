struct Query {
  int id, k;  // ���ѯ�ʵı��, ���ѯ�ʵ�k
};

int ans[N];        // ans[i] ��ʾ���Ϊi��ѯ�ʵĴ�
int check(int x);  // ����ԭ������С�ڵ���x�����ĸ���

void solve(int l, int r, vector<Query> q)
// �벹ȫ�������
{
  int m = (l + r) / 2;
  vector<Query> q1, q2;  // ������������ѯ�ʺ��Ҳ��ѯ��
  if (l == r) {
    // ...
    return;
  }
  // ...
  solve(l, m, q1), solve(m + 1, r, q2);
  return;
}

