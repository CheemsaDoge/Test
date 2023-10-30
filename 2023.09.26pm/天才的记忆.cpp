#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10, S = __lg(N) + 2;
int d[N][S], n, m, w[N];

inline void init() {
    for(int j(1); j <= S - 1; ++ j)
        for(int i(1); i + (1 << j) - 1 <= n; ++ i) 
            d[i][j] = max(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
    return ;
}

inline int query(int l, int r) {
    int g = __lg(r - l + 1);
    return max(d[l][g], d[r - (1 << g) + 1][g]);
}

int main() {
    cin >> n;
    for(int i(1); i <= n; ++ i) cin >> w[i], d[i][0] = w[i];
    init(); cin >> m;
    for(int x, y; m --; ) {
        cin >> x >> y;
        cout << query(x, y) << '\n';
    }
    return 0;
}
