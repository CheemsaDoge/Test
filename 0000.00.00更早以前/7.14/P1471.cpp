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
const int MAXN=1e6+1145;
#define db double 
struct	SEGtree{
	struct PA{
		int l,r;
		double val,tag;
	}rt[MAXN*4];
	struct PB{
		int l,r;
		double val,tag;
	}ft[MAXN*4];
	double totr,n;
	double value[MAXN];
	#define lch (a<<1)
	#define rch ((a<<1)+1)
	#define mid ((l+r)>>1)
	void Initialize(int nn)
	{
		n=nn;
		for(ri i=1;i<=n;i++)
			scanf("%lf",&value[i]);
		build(1,1,n);
	}
	void build(int a,int l,int r)
	{
		rt[a].l=l;rt[a].r=r;
		ft[a].l=l;ft[a].r=r;
		if(l==r){rt[a].val=value[l];ft[a].val=value[l]*value[l];return;}
		build(lch,l,mid);
		build(rch,mid+1,r);
		ft[a].val=ft[lch].val+ft[rch].val;
		rt[a].val=rt[lch].val+rt[rch].val;
	}
	void push_down(int a)
	{
		double tag=ft[a].tag;
		ft[a].tag=0;
		ft[lch].tag+=tag;
		ft[rch].tag+=tag;
		ft[lch].val+=2*tag*rt[lch].val+(rt[lch].r-rt[lch].l+1)*tag*tag;
		ft[rch].val+=2*tag*rt[rch].val+(rt[rch].r-rt[rch].l+1)*tag*tag;
		tag=rt[a].tag;
		rt[a].tag=0;
		rt[lch].tag+=tag;
		rt[rch].tag+=tag;
		rt[lch].val+=(rt[lch].r-rt[lch].l+1)*tag;
		rt[rch].val+=(rt[rch].r-rt[rch].l+1)*tag;
	}
	void part_add(int a,int x,int y,db k)
	{
		ri l=rt[a].l;
		ri r=rt[a].r;
		if(x<=l&&r<=y)	{
			ft[a].tag+=k;
			ft[a].val+=2*k*rt[a].val+(r-l+1)*k*k;
			rt[a].val+=(r-l+1)*k;
			rt[a].tag+=k;
			return;
		}
		if(rt[a].tag!=0||ft[a].tag!=0)
			push_down(a);
		if(x<=mid)	part_add(lch,x,y,k);
		if(y>mid)	part_add(rch,x,y,k);
		rt[a].val=rt[lch].val+rt[rch].val;
		ft[a].val=ft[lch].val+ft[rch].val;
	}
	db part_aska(int a,int x,int y)
	{
		int l=rt[a].l;
		int r=rt[a].r;
		if(x<=l&&r<=y)	return rt[a].val;
		db sum=0;	
		if(rt[a].tag!=0||ft[a].tag!=0)
			push_down(a);
		if(x<=mid)	sum+=part_aska(lch,x,y);
		if(y>mid)	sum+=part_aska(rch,x,y);
		return sum;
	}
	db part_askb(int a,int x,int y)
	{
		db sum=0;	
		push_down(a);
		int l=ft[a].l;
		int r=ft[a].r;
		if(x<=l&&r<=y)	return ft[a].val;
		if(x<=mid)	sum+=part_askb(lch,x,y);
		if(y>mid)	sum+=part_askb(rch,x,y);
		return sum;
	}
	double average(int x,int y)
	{
		db sum=part_aska(1,x,y);
		return double(sum)/(y-x+1*1.0);
	}
	double variance(int x,int y)
	{
		db a=average(x,y);
		db b=part_askb(1,x,y);
		db n=y-x+1;
		return (b/n)-part_aska(1,x,y)*part_aska(1,x,y)/n/n;
	}
}T;
int main()
{
	ri n,m;
	read(n);read(m);
	ri x,y;
	db k;
	T.Initialize(n);
	while(m--)
	{
		read(x);
		if(!(x-1)) read(x),read(y),scanf("%lf",&k),T.part_add(1,x,y,k);
		else if(!(x-2))	read(x),read(y),printf("%.4lf\n",T.average(x,y));
		else read(x),read(y),printf("%.4lf\n",T.variance(x,y));
	}	
}
