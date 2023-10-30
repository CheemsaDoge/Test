#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 3000;
const int M = 3005;
const int H = 35;
const ll mod = 1000000000;

int n;
int maxh[H], minh[H], L[M], R[M];
ll f[M][H], ans[M];

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
    //for(int i = 1; i <= 30; ++ i)
    //	cout << i << ' ' << minh[i] << ' ' << maxh[i] << '\n';
}

void DP() {
    int i, j, h, l, r;
    f[0][0] = f[1][1] = 1, ans[1] = 1;
    for (i = 2; i <= N; ++i){
        for (l = 0; l < i; ++l)
            for (r = i - l - 1, h = max(0, L[i] - 2); h <= min(29, R[i] - 1); ++h) {
                if (h > 0) (f[i][h + 1] += f[l][h] * f[r][h - 1]) %= mod;
                (f[i][h + 1] += f[l][h] * f[r][h]) %= mod;
                (f[i][h + 2] += f[l][h] * f[r][h + 1]) %= mod;
            }
        for (h = 1; h <= min(29, i); ++h)
            (ans[i] += f[i][h]) %= mod;
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
