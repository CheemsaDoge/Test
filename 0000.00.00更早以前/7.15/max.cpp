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
#define ri register int
int D;
struct segtree{
	struct pa{
		int l,r;
		ll maxn;
	}rt[MAXN*4];
	#define lch a*2
	#define rch a*2+1
	#define mid ((l+r)>>1)
	int value[MAXN];
	void build(int a,int l,int r)
	{
		rt[a].l=l;rt[a].r=r;
		if(l==r)
		{
			rt[a].maxn=value[l];
			return ;
		}
		build(lch,l,mid);
		build(rch,mid+1,r);
		rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
		return ;
	}
	void Initialize(int n)
	{
		for(int i=1;i<=n;i++)
			value[i]=0;
		build(1,1,n);
	}
	void change_single(int a,int x,int v)
	{
		int l=rt[a].l;
		int r=rt[a].r;
		if(rt[a].l==rt[a].r&&rt[a].r==x)
		{
			rt[a].maxn=v%D;
			return ;
		}
		if(x<=r&&x>mid)
			change_single(a*2+1,x,v);
		else if(x>=l&&x<=mid)
			change_single(a*2,x,v);
		else 
			return ;
		rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
		return ;
	}
	ll ask_part_maxn(int a,int l,int r)
	{
		ll maxn=0;
		if(rt[a].l>=l&&rt[a].r<=r)
			return rt[a].maxn;
		int midd=(rt[a].r+rt[a].l)/2; 
		if(l<=midd)
			maxn=max(maxn,ask_part_maxn(lch,l,r));
		if(r>=midd+1)
			maxn=max(maxn,ask_part_maxn(rch,l,r));
		return maxn;
	}
}T;

int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	ri m,tot=0,x,t=0;
	read(m);read(D);
	T.Initialize(m);
	while(m--)
	{
		if(getchar()=='A')
		{
			read(x);
			T.change_single(1,++tot,x+t);
		}
		else
		{
			read(x);
			t=T.ask_part_maxn(1,tot-x+1,tot);
			printf("%lld\n",t);
		}
	}
}
