#include <stdio.h>
#include <string.h>
#define max(a,b) a>b?a:b
const int N = 2005;
int i, j, t, nn = 0, mm = 0, k, n[10005], m[10005];
int c[N][N], sum[N][N];
int main() {
	freopen("problem.in", "r", stdin);
	freopen("problem.out", "w", stdout);

    
    scanf("%d%d", &t, &k);

    for (i = 1; i <= t; i++) {
        scanf("%d%d", &n[i], &m[i]);
        nn = max(nn, n[i]);
        mm = max(mm, m[i]);
    }

    for (i = 0; i <= nn; i++) {
        c[i][0] = 1;
    }

    for (i = 1; i <= nn; i++) {
        for (j = 1; j <= mm; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;

            if (c[i][j] == 0 && j <= i)
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + 1;
            else
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for (i = 1; i <= t; i++) {
        printf("%d\n", sum[n[i]][m[i]]);
    }

    return 0;
}
