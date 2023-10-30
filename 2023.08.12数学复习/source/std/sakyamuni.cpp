#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3000;
const int M = 3005;
const int H = 35;
const ll mod = 1000000000;

int n;
int maxh[H], minh[H], L[M], R[M];
ll dp[M][H], ans[M];

inline int read() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || '9' < ch)
        ch = getchar();
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void pre_work() {
    int i, j;
    minh[1] = maxh[1] = 1, minh[2] = 2, maxh[2] = 3;
    for (i = 3; i <= 30; ++i)
        minh[i] = minh[i - 1] + minh[i - 2] + 1,
        maxh[i] = maxh[i - 1] << 1 | 1;
    for (i = 1; i <= 30 && minh[i] <= N; ++i)
        for (j = minh[i]; j < min(minh[i + 1], N + 1); ++j)
            R[j] = i;
    for (L[1] = 1, i = 2; i <= 30 && maxh[i - 1] <= N; ++i)
        for (j = maxh[i - 1] + 1; j <= min(maxh[i], N); ++j)
            L[j] = i;

}

void DP() {
    int i, j, h, l, r;
    dp[0][0] = dp[1][1] = 1, ans[1] = 1;
    for (i = 2; i <= N; ++i){
        for (l = 0; l < i; ++l)
            for (r = i - l - 1, h = max(0, L[i] - 2); h <= min(29, R[i] - 1); ++h) {
                if (h) dp[i][h + 1] += dp[l][h] * dp[r][h - 1];
                (dp[i][h + 1] += dp[l][h] * dp[r][h]) %= mod;
                dp[i][h + 2] += dp[l][h] * dp[r][h + 1];
            }
        for (h = 1; h <= min(29, i); ++h)
            ans[i] += dp[i][h];
        ans[i] %= mod;
    }
}

int main() {
	freopen("sakyamuni.in", "r", stdin);
	freopen("sakyamuni.out", "w", stdout);

    pre_work();
    DP();
    while ((n = read()) != 0)
        printf("%lld\n", ans[n]);
    return 0;
}
