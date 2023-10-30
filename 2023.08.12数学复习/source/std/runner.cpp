#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>

#define ll long long
using namespace std;
const int mod = 10007;

ll QuickPow(ll x, ll N) {
    ll res = x % mod;
    ll ans = 1;
    while (N) {
        if (N & 1) {
            ans = ans * res % mod;
        }
        res = res * res % mod;
        N = N / 2;
    }
    return ans % mod;
}

ll C(ll n, ll m) {
    if (m > n) {
        return 0;
    }
    ll ans = 1;
    for (int i = 1; i <= m; i++) {
        ll a = (n + i - m) % mod;
        ll b = i % mod;
        ans = ans * (a * QuickPow(b, mod - 2) % mod) % mod;
    }
    return ans;
}

ll lucas(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    return C(a % mod, b % mod) * lucas(a / mod, b / mod) % mod;
}

int main() {
	freopen("runner.in", "r", stdin);
	freopen("runner.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		ll n;
	    scanf("%lld", &n);
//	    n--;
	    printf("%lld\n", ((lucas(2 * n, n) - lucas(2 * n, n - 1) + mod) % mod) * 2 % mod);
	}
    
}

