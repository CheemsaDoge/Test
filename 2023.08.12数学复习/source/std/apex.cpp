#include <algorithm>
#include <cstdio>
#include <set>

typedef long long ll;

inline int read() {
	char c=getchar();
	int x=0,ft=1;
	for(; c<'0'||c>'9'; c=getchar()) if(c=='-') ft=-1;
	for(; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
	return x*ft;
}

inline ll ll_read() {
	char c=getchar();
	ll x=0,ft=1;
	for(; c<'0'||c>'9'; c=getchar()) if(c=='-') ft=-1;
	for(; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
	return x*ft;
}

const int N=1e5+5;

int n,q;
ll a[N],b[N],m[N],r[N];
std::multiset<ll> atk;
std::multiset<ll> :: iterator it;

inline void exgcd(ll a,ll b,ll &x,ll &y,ll &d) {
	if(!b) {
		x=1;
		y=0;
		d=a;
		return;
	}
	exgcd(b,a%b,y,x,d);
	y-=(a/b)*x;
}

inline ll mul(ll a,ll b,ll mod) {
	ll tmp=(long double)a*b/mod;
	return ((a*b-tmp*mod)%mod+mod)%mod;
}

inline ll excrt() {
	ll A,B,C,x,y,d,lcm=1,ans=0;
	for(int i=1; i<=n; ++i) {
		A=a[i]*lcm;
		B=m[i];
		C=(b[i]+m[i]-a[i]*ans%m[i])%m[i];
		exgcd(A,B,x,y,d);
		if(C%d) return -1;
		x=mul(x,C/d,B/d);
		ans+=x*lcm;
		lcm*=B/d;
		ans=(ans%lcm+lcm)%lcm;
	}
	return ans;
}

inline bool check_p() {
	for(int i=1; i<=n; ++i) if(m[i]!=1) return 0;
	return 1;
}

inline ll work() {
	ll ans=0;
	for(int i=1; i<=n; ++i) {
		ans=std::max(ans,(b[i]+a[i]-1)/a[i]);
	}
	return ans;
}

inline void solve() {
	n=read();
	q=read();
	atk.clear();
	for(int i=1; i<=n; ++i) b[i]=ll_read();
	for(int i=1; i<=n; ++i) m[i]=ll_read();
	for(int i=1; i<=n; ++i) r[i]=ll_read();
	for(int i=1; i<=q; ++i) atk.insert(ll_read());
	for(int i=1; i<=n; ++i) {
		it=atk.upper_bound(b[i]);
		if(it!=atk.begin()) --it;
		a[i]=(*it);
		atk.erase(it);
		atk.insert(r[i]);
	}
	printf("%lld\n",check_p()?work():excrt());
}

int main() {
	freopen("apex.in","r",stdin);
	freopen("apex.out","w",stdout);
	int cases=read();
	while(cases--) solve();
	return 0;
}
