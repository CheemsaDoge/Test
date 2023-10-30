#include<bits/stdc++.h>
#define MAXN 100010
#define INF 1000000001
using namespace std;
struct Node{
	int l,r; //
	int lch,rch;//
	int tag;//
}rt[MAXN*2];
int totr=0;//
int a[MAXN];//
void calc(int x)//
{
	rt[x].tag=rt[rt[x].lch].tag+rt[rt[x].rch].tag;
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
		return 0;
	return query(rt[x].lch,l,r)+query(rt[x].rch,l,r);
}
void modify(int x,int y,int v)
{
	if(rt[x].l==rt[x].r)
	{
		rt[x].tag+=v;
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
