#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rl register unsigned long long
#define ri register int
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const ll MAXN = 1e6+1145;
struct STACK{
	unsigned ll tot;
	unsigned ll a[MAXN];
	inline void initialize()
	{
		memset(a,0,sizeof(a));
		tot=0;
	}
	inline bool empty()
	{
		return tot?false:true;
	}
	inline void push(int x)
	{
		a[++tot]=x;
	}
	inline void query()
	{
		if(empty())	printf("Anguei!\n");
		else	printf("%lld\n",a[tot]);
	}
	inline void pop()
	{
		if(empty())	printf("Empty\n");
		else tot--;
	}
	inline unsigned ll size()
	{
		return tot;
	}
}sta;
int main() 
{
	string op;
	rl n,x,T;
	read(T);
	while(T--)
	{
		read(n);
		sta.initialize();
		for(ri i=1;i<=n;i++)
		{
			cin>>op;
			if(op=="push")
			{
				read(x);
				sta.push(x);
			}
			else if(op=="query")
				sta.query();
			else if(op=="size")
				printf("%lld\n",sta.size());
			else
				sta.pop();
		}
	}
}
