/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=20;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
ll n;
ll lcm(ll a,ll b) {
	ll t = __gcd(a, b);
	double chk = 1.0 * a / t * b;
	if(chk > n) return n + 1;
	if(1.0 * a / t * b > n) return n + 1;
	return a / t * b;
}
long long mi[20];
void Pre()
{
	ll zan=1;
	for(int i=0;i<=18;i++){
		mi[i]=zan;
		zan*=-2;
	}
}
vector<long long>x[MAXM];
queue<long long>zan[MAXM];
ll m,qq,ans;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);	
	read(n);read(m);
	Pre();
	for(int i=1;i<=m;i++) 
	{
		read(qq);
		for(int j=1;j<=m;j++){
			if(x[j].empty()) break;
			for(int p=0;p<x[j].size();p++) zan[j+1].push(lcm(qq,x[j][p]));
		}
		x[1].push_back(qq);
		for(int j=2;j<=m;j++){
			if(zan[j].empty()) break;
			while(!zan[j].empty()) x[j].push_back(zan[j].front()),zan[j].pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<x[i].size();j++){
			ans+=mi[i-1]*(n/x[i][j]);
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}
