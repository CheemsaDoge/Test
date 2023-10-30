
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

int main(int argc, char *argv[]) {
	freopen("hack.out", "r", stdin);
	cin >> n >> l >> s;
	for (auto c : s) insert(c);
	int ans = 0;
	for (int i=1; i<=tot; ++i)
		if (SAM[SAM[i].link].len < l && l <= SAM[i].len)
			++ans;
	cout << ans;
	return 0;
}
