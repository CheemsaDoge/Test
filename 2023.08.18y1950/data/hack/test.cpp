#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;

const int MaxN = 100000;

inline int hash_handle(const string &s, const int &n, const int &l, const int &base)
{
 u64 hash_pow_l = 1;
 for (int i = 1; i <= l; i++)
  hash_pow_l *= base;

 int li_n = 0;
 static u64 li[MaxN];

 u64 val = 0;
 for (int i = 0; i < l; i++)
  val = val * base + s[i] - 'a';
 li[li_n++] = val;
 for (int i = l; i < n; i++)
 {
  val = val * base + s[i] - 'a';
  val -= (s[i - l] - 'a') * hash_pow_l;
  li[li_n++] = val;
 }

 sort(li, li + li_n);
 li_n = unique(li, li + li_n) - li;
 return li_n;
}

int n, l;
string s;

int main(int argc, char *argv[]) {
	freopen("hack.out", "r", stdin);
	cin >> n >> l >> s;
	cout << hash_handle(s, n, l, 3);
	return 0;
}
