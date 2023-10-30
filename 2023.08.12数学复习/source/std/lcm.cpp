#include<bits/stdc++.h>

using namespace std;
long long rand_seed() {
	long long a = rand();
	return a;
}
long long a, b;
int main() {
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);

	cin >> a >> b;
	long long dif = abs(a - b);
	vector<int>v;
	for(int i = 1; i * i <= dif; ++i) {
		if(dif % i) continue;
		v.push_back(i);
		if(i * i != dif)
			v.push_back(dif / i);
	}
	long long ans = (1LL<<62);
	long long ans_k = 0;
	sort(v.begin(), v.end());
	for(int i = 0; i < (int)v.size(); ++i) {
		int q = v[i];
		if(a % q != b % q) continue;
		long long k = (q - a % q) % q;
		long long lcm = ((k + a) * (k + b))/__gcd((k + a), (k + b));
		if(lcm <= ans) {
			if(lcm == ans) 
				ans_k = min(k, ans_k);
			else 
				ans = lcm, ans_k = k;
		}
	}
	cout << ans_k;
	return 0;
}
