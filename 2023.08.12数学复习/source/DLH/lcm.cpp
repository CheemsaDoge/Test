/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXT=1e4+1145;const int MAXN=2e3+2;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int a,b;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);	
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
