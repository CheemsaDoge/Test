#include<bits/stdc++.h>
#define MAXN 100010
#define INF 1000000001
using namespace std;
struct Node{
	long long l,r; //
	long long lch,rch;//
	long long tag;//
}rt[MAXN*2];
long long totr=0;//
long long a[MAXN];//
void calc(int x)//
{
	rt[x].tag=max(rt[rt[x].lch].tag,rt[rt[x].rch].tag);
}
void build(long long l,long long r)
{
	totr++;
	long long x=totr;
	rt[x].l=l;
	rt[x].r=r;
	if(l==r)
	{
		rt[x].tag=a[l];
		return ;
	}
	long long mid=(l+r)/2;
	rt[x].lch=totr+1;build(l,mid);
	rt[x].rch=totr+1;build(mid+1,r);
	calc(x);
	return ;
}
long long query(long long x,long long l,long long r)
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
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	build(1,n);
	
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,l,r));
	}
	return 0;
}
