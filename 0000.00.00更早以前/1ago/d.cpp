#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=1e6+1145;
struct T{
	struct part{
		int l,r;
		int val,tag,maxn;
		int lch,rch;
	}rt[MAXN*4];
	int tot;
	int value[MAXN];
	void Initialize(int n)
	{
		tot=0;
		for(int i=1;i<=n;i++)
			read(value[i]);
	}
	#define mid ((l+r)/2)
	int build(int l,int r)
	{
		tot++;
		int a=tot;
		if(l==r)
		{
			rt[a].val=value[l];
			rt[a].maxn=value[l];
			return a;
		}
		rt[a].l=l;
		rt[a].r=r;
		rt[a].lch=build(l,mid);
		rt[a].rch=build(mid+1,r);
		return a;
	}
	void change_point(int a,int x,int p)
	{
		int l=rt[a].l;int r=rt[a].r;
		if(l==r)
		{
			rt[a].val=p;
			return;
		}
		if(x<=mid)	change_point(rt[a].lch,x,p);
		if(x>mid)	change_point(rt[a].rch,x,p);
		rt[a].val=rt[rt[a].lch].val+rt[rt[a].rch].val;
		rt[a].maxn=max(rt[rt[a].lch].val,rt[rt[a].rch].val);	
	}
	#define lp rt[a].lch
	#define rp rt[a].rch
	#define length rt[a].r-rt[a].l+1
	void spread(int x)
	{
		
	}
	void add_part(int l,int r,int a,int d)
	{
		if(rt[a].l>=l&&rt[a].r<=r)
		{
			rt[a].tag+=d;
			rt[a].val+=d*(length);
		}
	}
};

int main()
{
	
}
