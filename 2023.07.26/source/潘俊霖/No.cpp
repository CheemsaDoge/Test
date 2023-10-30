#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int x, y, dp[500][53], p[500];
inline void pre() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= 16; i++) {
		dp[i][0] = dp[i - 1][0] * 9 - dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1] + dp[i - 1][0];
	}
}
inline int cal(int x) {
	int cnt = 0, ans = 0, tmp = x;
	while (x) {
		p[++cnt] = x % 10;
		x /= 10;
	}
	bool flag = 0;
	p[cnt + 1] = 0;
	for (int i = cnt; i; i--) {
		ans += p[i] * dp[i - 1][2];
		if (flag)
			ans += p[i] * dp[i - 1][0];
		else {
			if (p[i] > 4) ans += dp[i - 1][0];
			if (p[i] > 6) ans += dp[i - 1][1];
			if (p[i] > 2 && p[i + 1] == 6) ans += dp[i][1];
			if (p[i] == 4 || (p[i] == 2 && p[i + 1] == 6)) flag = 1;
		}
	}
	return tmp - ans;
}
int main() {
	freopen("No.in","r",stdin);
	freopen("No.out","w",stdout);
	pre();
	while (~scanf("%d%d", &x, &y)) {
		if (!x && !y) break;
		x = min(x, y), y = max(x, y);
		printf("%d\n", cal(y + 1) - cal(x));
	}
}
