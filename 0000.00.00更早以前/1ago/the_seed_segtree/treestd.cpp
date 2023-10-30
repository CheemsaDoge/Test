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
struct segtree{
	struct pa{
		int l,r;
		ll val,maxn,addtag,multag;
	}rt[MAXN*4];
	#define lch a*2
	#define rch a*2+1
	#define mid ((l+r)>>1)
	int value[MAXN];
	void Initialize(int n)
	{
		for(int i=1;i<=n;i++)
			read(value[i]);
	}
	void build(int a,int l,int r)
	{
		rt[a].l=l;rt[a].r=r;
		if(l==r)
		{
			rt[a].val=value[l];
			rt[a].maxn=value[l];
			return ;
		}
		build(lch,l,mid);
		build(rch,mid+1,r);
		rt[a].val=rt[lch].val+rt[rch].val;
		rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
		return ;
	}
	inline void pushdown(int a)
	{
		if(rt[a].addtag!=0)
		{
			pushdown(lch);
			pushdown(rch);
			int addtag=rt[a].addtag;
			rt[lch].addtag+=addtag;
			rt[rch].addtag+=addtag;
			rt[lch].val+=(rt[lch].r-rt[lch].l+1)*addtag;
			rt[lch].maxn+=addtag;
			rt[rch].val+=(rt[rch].r-rt[rch].l+1)*addtag;
			rt[rch].maxn+=addtag;
			rt[a].addtag=0;
		}
		if(rt[a].addtag!=0)
		{
			
		}
	}
	void change_single(int a,int x,int v)
	{
		pushdown(a);
		int l=rt[a].l;
		int r=rt[a].r;
		if(rt[a].l==rt[a].r&&rt[a].r==x)
		{
			rt[a].val=v;
			rt[a].maxn=v;
			return ;
		}
		if(x<=r&&x>mid)
			change_single(a*2+1,x,v);
		else if(x>=l&&x<=mid)
			change_single(a*2,x,v);
		else 
			return ;
		rt[a].val=rt[lch].val+rt[rch].val;
		rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
		return ;
	}
	void add_part(int a,int l,int r,int v)
	{
		pushdown(a);
		if(rt[a].l>=l&&rt[a].r<=r)
		{
			rt[a].addtag+=v;
			rt[a].val+=(rt[a].r-rt[a].l+1)*v;
			rt[a].maxn+=v;
			return ;
		}
		int midd=(rt[a].r+rt[a].l)>>1; 
		if(l<=midd)
			add_part(lch,l,r,v);
		if(r>midd)
			add_part(rch,l,r,v);
		rt[a].val=rt[lch].val+rt[rch].val;
		rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
		return ;
	}
	void multiplicate_part(int a,int l,int r,int v)
	{
		pushdown(a);
		if(rt[a].l>=l&&rt[a].r<=r)
		{
			rt[a].tag+=v;
			rt[a].val+=(rt[a].r-rt[a].l+1)*v;
			rt[a].maxn+=v;
			return ;
		}
		int midd=(rt[a].r+rt[a].l)>>1; 
		if(l<=midd)
			add_part(lch,l,r,v);
		if(r>midd)
			add_part(rch,l,r,v);
		rt[a].val=rt[lch].val+rt[rch].val;
		rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
		return ;
	}
	}
	ll ask_part_sum(int a,int l,int r)
	{
		ll sum=0;
		pushdown(a);
		if(rt[a].l>=l&&rt[a].r<=r)
			return rt[a].val;
		int midd=(rt[a].r+rt[a].l)/2; 
		if(l<=midd)
			sum+=ask_part_sum(lch,l,r);
		if(r>=midd+1)
			sum+=ask_part_sum(rch,l,r);
		return sum;
	}
}T;
int n,m;
int l,r,op,x,y;
int main()
{
//	freopen("segtree.in","r",stdin);
//	freopen("segtree.out","w",stdout);
	read(n);
	read(m);
	T.Initialize(n);
	T.build(1,1,n);
	while(m--)
	{
		read(op);
		if(op==1)
		{		
			read(l);
			read(r);
			read(x);
			T.add_part(1,l,r,x);
		}
		else
		{
			read(l);
			read(r);
			printf("%lld\n",T.ask_part_sum(1,l,r));
		}
	}
	return 0;
}
