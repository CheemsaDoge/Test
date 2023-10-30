#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+1145;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ll long long int 
struct BIT{
	ll pt[MAXN];
	ll nn,value[MAXN];
	inline ll ask(ll i)
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
		for(int i=1;i<=n;i++)
			read(value[i]);
		for(int i=1;i<=n;i++)
			add(i,value[i]-value[i-1]);
	}
}T;
int c[MAXN];
int main(){
//	freopen("BIT.in","r",stdin);
//	freopen("BIT.out","w",stdout);
	ll n,m,op,l,x,r;
	read(n);
	read(m);
	T.Initialize(n);
	while(m--)
	{
		read(op);
		if(op==1)
		{		
			read(l);
			read(r);
			read(x);
			T.add(l,x);
			T.add(r+1,-x);
		}
		else
		{
			read(l);
			read(r);
			printf("%lld\n",T.ask(r)-T.ask(l-1));
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%d ",T.pt[i]); 
}
