
#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, l;
string s;
ifstream fin, fout, fans;
ofstream fscore,freport;

int tot=0, cur, last;
char T[MAXN];

struct Node {
	int len, link, cnt;
	int next[26];
	vector<int> edge;
} SAM[MAXN<<1];

void insert(char x) {
	if (x < 'a' || 'z' < x) {
		fscore<< 0 << endl;
		freport<< "c < 'a' || 'z' < c" << endl;
		exit(0);
	}
	int c = x - 'a';
	int p = last, q;
	cur = ++tot;
	SAM[cur].len = SAM[last].len + 1;
	SAM[cur].cnt = 1;
	for (; ~p && !SAM[p].next[c]; p = SAM[p].link)
		SAM[p].next[c] = cur;
	last = cur;
	if (p == -1) {
		SAM[cur].link = 0;
		return;
	}
	q = SAM[p].next[c];
	if (SAM[p].len + 1 == SAM[q].len) {
		SAM[cur].link = q;
		return;
	}
	int clone = ++tot;
	SAM[clone] = SAM[q];
	SAM[clone].len = SAM[p].len + 1;
	SAM[clone].cnt = 0;
	SAM[cur].link = SAM[q].link = clone;
	for (; ~p && SAM[p].next[c] == q; p = SAM[p].link) SAM[p].next[c] = clone;
}

int hash_handle(const string &s, const int &n, const int &l, const int &base);

vector<int> Base = {3, 16, 19260817, 19491001, 1000000007, 998244353, 1000000000, 50000000};

int main(int argc, char *argv[]) {
	fout.open(argv[2]);
	fscore.open(argv[5]);
    freport.open(argv[6]);
    int score=atoi(argv[4]);
//	n = ouf.readInt(1, 100000, "n");
	fout >> n;
	if (n < 1 || n > 100000) {
		fscore<< 0 << endl;
		freport<< "n < 1 || n > 100000" << endl;
		return 0;
	}
	fout >> l;
	if (l < 1 || l > n) {
		fscore<< 0 << endl;
		freport<< "l < 1 || l > n" << endl;
		return 0;
	}
	
//	l = ouf.readInt(1, n, "l");
	char re[100]; 
//	sprintf(re, "[a-z]{%d}", n);
//	s = ouf.readToken(re, "string");
	fout >> s;
	SAM[0].link = -1;
	SAM[0].len = 0;
	last = 0;
	for (auto c : s) insert(c);
	int ans = 0;
	for (int i=1; i<=tot; ++i)
		if (SAM[SAM[i].link].len < l && l <= SAM[i].len)
			++ans;
	for (auto base : Base)
	if (hash_handle(s, n, l, base) == ans) {
		fscore<< 0 << endl;
		sprintf(re, "当 base = %d 时 hash 代码结果正确", base);
		freport<< re << endl;
		return 0;
	}
	fscore<< score << endl;
	freport<< "Accepted" << endl;
	return 0;
}

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
