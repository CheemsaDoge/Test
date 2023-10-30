#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define ull unsigned long long

const int N = 4e5 + 100;
const int M = 4e5 + 100;

char str[N];
ull  tmpl, tmpr, tmp_len;
ull  power[N], Hash[N];
set<ull>sc;

ull getHash(int l, int r) {
	if (l > r) return 0;
	return  Hash[r] - Hash[l - 1] * power[r - l + 1];
}
int  ans;
void init(int n) {
	memset(Hash, 0, sizeof(Hash));
	memset(power, 0, sizeof(power));
	ans = 0;
	sc.clear();
	power[0] = 1;

	for (int i = 1; i <= n; i++) {
		Hash[i] = Hash[i - 1] * (ull)131 + (ull)(str[i] - 'A' + 1);
		power[i] = power[i - 1] * (ull)131;
	}
}
void sol(int n) {
	for(int i = 1; i <= n; i++) {
		tmp_len = 0;
		if (i == 1) {
			tmpl = getHash(2, (n - 1) / 2 + 1);
			tmpr = getHash((n - 1) / 2 + 2, n);
		} else if(i == n) {
			tmpl = getHash(1, (n - 1) / 2);
			tmpr = getHash((n - 1) / 2 + 1, n - 1);
		} else if (i == n / 2 + 1) {
			tmpl = getHash(1, i - 1);
			tmpr = getHash(i + 1, n);
		} else if (i <= n / 2) {
			tmp_len = n / 2 + 1 - i;
			//*********
			tmpl = getHash(1, i - 1) * power[tmp_len] + getHash(i + 1, n / 2 + 1);
			tmpr = getHash(n / 2 + 2, n);
		} else {
			tmp_len = n - i;
			tmpl = getHash(1, n / 2);
			tmpr = getHash(n / 2 + 1, i - 1) * power[tmp_len] + getHash(i + 1, n);
		}

		if (tmpl == tmpr) {
			sc.insert(tmpl);
			ans = i;
		}
	}
}
void mycout(int n) {
	if (sc.size() == 0) {
		puts ("NOT POSSIBLE");
	} else if (sc.size() > 1) {
		puts ("NOT UNIQUE");
	} else {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if(ans == i) continue;
			printf("%c", str[i]);
			cnt ++;
			if (cnt == (n - 1) / 2) {
				puts("");
				break;
			}

		}
	}
}
int n;
int main () {
	scanf("%d", & n);
	scanf("%s", str + 1);
	if (n % 2 == 0) {
		puts("NOT POSSIBLE");
		continue;
	}
	init(n);
	sol(n);
	mycout(n);
	return 0;
}
