#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define MAXN 1000000+114514
#define INF 1000000001
using namespace std;
struct Node{
	int l,r; //
	int lch,rch;//
	int tag;//
}rt[MAXN*4];
int totr=0;//
int a[MAXN];//
void calc(int x)//
{
	rt[x].tag=max(rt[rt[x].lch].tag,rt[rt[x].rch].tag);
}
void build(int l,int r)
{
	totr++;
	int x=totr;
	rt[x].l=l;
	rt[x].r=r;
	if(l==r)
	{
		rt[x].tag=a[l];
		return ;
	}
	int mid=(l+r)/2;
	rt[x].lch=totr+1;build(l,mid);
	rt[x].rch=totr+1;build(mid+1,r);
	calc(x);
	return ;
}
int query(int x,int l,int r)
{
	if(l<=rt[x].l&&rt[x].r<=r){///
		return rt[x].tag;
	}
	if(l>rt[x].r||r<rt[x].l)
		return -INF;
	return max(query(rt[x].lch,l,r),query(rt[x].rch,l,r));
}

int query1(int x,int l,int r)
{
	if(l<=rt[x].l&&rt[x].r<=r){//
		return rt[x].tag;
	}
	int mid=(rt[x].l+rt[x].r)/2,ret=-INF;
	if(l<=mid) ret=max(ret,query1(rt[x].lch,l,r));
	if(r>=mid+1) ret=max(ret,query1(rt[x].rch,l,r));
	return ret;
}
void modify(int x,int y,int v)
{
	if(rt[x].l==rt[x].r)
	{
		rt[x].tag=v;
		return ;
	}
	int mid=(rt[x].l+rt[x].r)/2;
	if(y<=mid)modify(rt[x].lch,y,v);
	if(y>mid)modify(rt[x].rch,y,v);
	calc(x);
}
int main()
{
	freopen("candle.in","r",stdin);
	freopen("candle.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		read(a[i]);
		
	build(1,n);
	for(int i=1;i<=n;i++)
		printf("%d\n",query(1,max(i-k,1),min(n,i+k)));
}
