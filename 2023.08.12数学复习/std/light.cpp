#include<bits/stdc++.h>
typedef int INT;
#define int long long
using namespace std;
const int N = 105;
int A[N], h[N], C[N][N];
int n,m;
int lcm(int a,int b) {
	int t = __gcd(a, b);
	double chk = 1.0 * a / t * b;
	if(chk > n) return n + 1;
	if(1.0 * a / t * b > n) return n + 1;
	return a / t * b;
}
INT main() {
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < m; ++ i) 
		cin >> A[i];
	int ans = 0;
	C[0][0] = 1;
	for(int i = 1; i <= m; ++ i){
		C[i][0] = 1;
		for(int j = 1; j <= i; ++ j)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	
	h[1] = 1;
	for(int i = 2; i <= m; ++ i) {
		int d = i & 1 ? 1 : 0 , x = 0;
		for(int j = 1; j < i; ++ j) x += h[j] * C[i][j];
		h[i] = d - x;
	}
	
	for(int S = 0; S < 1 << m; ++ S){
		int mul = 1, cnt = 0;
		for(int i = 0; i < m; ++ i) 
			if(S & (1 << i)) {
				mul = lcm(mul , A[i]);
				if(mul > n || mul < 0) break;
				cnt ++;
			}
		if(mul > n || mul < 0) continue;
		ans += h[cnt] * (n / mul);
	}
	cout << ans;
	return 0;
} 
