#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MOD=998244353;
const int MAXN=1e6+1145;
#define ri register int
#define rl register long long 
#define ll long long
ll jiecheng[MAXN];
ll a[MAXN];
struct BIT{
	ll pt[MAXN];
	ll nn,value[MAXN];
	inline ll ask(ll i)
	{
		ll sum=0;
		while(i)	sum+=pt[i],i-=i & -i;
		return sum;
	}
	inline void add(int i,int x)
	{
		while(i<=nn)
		{
			pt[i]+=x;
			i += i & -i;
		}
	}
	inline void Initialize(int n)
	{
		nn=n;
		for(int i=1;i<=n;i++)
			add(i,1);
	}
}T;
int main()
{
//	freopen("cantor.in","r",stdin);
//	freopen("cantor.out","w",stdout);
	rl n=0;
	rl sum=1;
	read(n);
	for(ri i=1;i<=n;i++)
	{
		sum*=i;
		sum%=MOD;
		jiecheng[i]=sum;
	}
	sum=0;
	T.Initialize(n);
	for(int i=1;i<=n;i++)
	{	
		read(a[i]);
		T.add(a[i],-1);
		sum+=T.ask(a[i])*(jiecheng[n-i]);
		if(sum>MOD)
			sum-=MOD*(sum/MOD);
	
	}
	printf("%lld",sum+1);
}

