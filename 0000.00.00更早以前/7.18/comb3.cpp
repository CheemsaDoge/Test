#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define rl register long long 
#define ll long long
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MOD=1e9+7;
priority_queue<int>c;
inline ll C(ll n,ll m)
{
	rl sum=1;
	for(ri i=1;i<=n;i++)
		sum*=i;
	for(ri i=1;i<=m;i++)
		sum/=i;
	for(ri i=1;i<=n-m;i++)
		sum/=i;
	return sum;
}
ll a[1000][1000];
#define up (a[i-1][j])
#define left (a[i-1][j-1])
int main()
{
//	freopen("comb3.in","r",stdin);
//	freopen("comb3.out","w",stdout);
	rl n,k;
	read(n);read(k);
	a[1][1]=1;
	if(n>750&&k!=1)
		return 0;
	if(k==1&&n>500)
	{
		printf("%lld\n",C(n,n/2));
		return 0;
	}
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i;j++)
		{
			a[i][j]+=(up+left)%MOD;
			c.push(a[i][j]);
		}
	rl sum=0;
	for(int i=1;i<=k;i++)
	{
		sum+=c.top();
		c.pop();
		sum%=MOD;
	}
	printf("%lld\n",sum);
}
