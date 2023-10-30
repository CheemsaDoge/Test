#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
const int MAXN=2e5+1145ll;
#define ll long long
#define ri register int
#define rl register long long
struct BIT{
	ll pt[MAXN];
	ll nn,value[MAXN];
	inline ll query(ll i)
	{
		ll sum=0;
		while(i)
		{
			sum+=pt[i];
			i-=i & -i;
		}
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
//		for(int i=1;i<=n;i++)
//			read(value[i]);
//		for(int i=1;i<=n;i++)
//			add(i,value[i]-value[i-1]);
	}
	inline void ask(ll x)
	{
		rl ti=query(x);
		if(ti%2) puts("1");
		else puts("0");
	}
}T;
int op,t,x,y,z,n;
int main() {
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	read(n);
	read(t);
	T.Initialize(n);
	while(t--)
	{
		read(op);
		read(x);
		if(op==1)
		{
			read(y);
			T.add(x,1);
			T.add(y+1,-1);
		}
		else
			T.ask(x);
	}
	return 0;
}

