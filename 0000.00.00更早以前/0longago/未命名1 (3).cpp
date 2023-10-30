#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define mid ((l+r)>>1)
#define nl (tot<<1)
#define nr (tot<<1|1)
#define length (r-l+1)
const int MAXN=1e6+1145;
int a[MAXN];
int tot=0;
struct SeegmentTree{
	struct Part{
		int l,r;
		int lch,rch;
		int tag,val;
	}rt[MAXN*4];
	inline int build(int x,int l,int r)
	{
		rt[x].tag=0;
		rt[x].l=l;
		rt[x].r=r;
		if(l>r)
			return 0;
		if(l==r) 
		{
			rt[x].val=a[l];
			return rt[x].val;	
		}
		rt[x].lch=nl;
		rt[x].rch=nr;
		rt[x].val=build(x*2,l,mid)+build(x*2+1,mid+1,r);
		return rt[x].val;
	}
	void pushdown(int x)
	{
		int l=rt[x].l;
		int r=rt[x].r;
		rt[rt[x].lch].tag+=rt[x].tag;
		rt[rt[x].rch].tag+=rt[x].tag;
		rt[x].val+=length*rt[x].tag;
		rt[x].tag=0;
	}
	void add(int x,int l,int r,int y)
	{
		if(rt[x].l>=l||rt[x].r<=r)	{
			rt[x].tag+=y;
			pushdown(x);
			return ;	
		}
		if(l<=mid)	add(rt[x].lch,l,mid,y);
		if(r>mid)	add(rt[x].rch,mid+1,r,y);	
	}
	inline int query(int x,int l,int r)
	{
		int ans=0;
		pushdown(x);
		if(rt[x].l>=l&&rt[x].r<=r)	return rt[x].val;
		if(l<=mid)	ans+=query(rt[x].lch,rt[x].l,rt[x].r);
		if(r>mid)	ans+=query(rt[x].rch,rt[x].l,rt[x].r);
		return ans;
	}
}T;
int main()
{
	int n,m,k;
	read(n);read(m);
	int op;
	int x,y;
	for(int i=1;i<=n;i++)
		read(a[i]);
	T.build(1,1,n);
	printf("%d\n",T.rt[2].val);
	while(m--)
	{
		read(op);read(x);read(y);
		if(op==1)
		{
			read(k);
			T.add(1,x,y,k);
		}
		else
			printf("%d\n",T.query(1,x,y));
	}
}
