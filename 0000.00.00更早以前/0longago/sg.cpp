#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define Rint register int
#define MAXN 1000000+1145
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
int n,m;

struct Tree{
	struct part{
		int l,r;
		int val,tag,maxn;
	}rt[MAXN*4];
	int tot;
	void calc(int x)
	{
		r
	}
	void built(int l,int r)
	{
		rt[++tot].l=l;
		rt[tot].r=r;
		rt[tot].val=
	}
};




int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n);
	while(m--){
		int l,r;
		LL v;
		scanf("%d%d%lld",&l,&r,&v);
		modify(1,l,r,v);
		printf("%lld\n",query1(1,l,r));
	}
	return 0;
	
}
