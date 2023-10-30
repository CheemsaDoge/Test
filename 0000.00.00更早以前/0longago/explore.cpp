#include<bits/stdc++.h>
using namespace std;
#define LL long long
const long long int N=1e6+1145;
long long int totr,n,m,a[N];
struct INT
{
	long long int l,r;
	long long int rch,lch;
	long long int light,sum;
}rt[N*3];
int calc(int x)
{
	return rt[x].sum+rt[x].light*(rt[x].r-rt[x].l+1);
}
void push_up(int x)
{
	rt[x].sum=calc(rt[x].lch)+calc(rt[x].rch);
}
void push_down(int x){
	rt[rt[x].lch].light+=rt[x].light;
	rt[rt[x].rch].light+=rt[x].light;
	rt[x].light=0;
}
void build(int l,int r)
{
	totr++;
	int x=totr;
	rt[x].l=l;
	rt[x].r=r;
	if(l==r)
	{
		rt[x].sum=a[l];
		return ;
	}
	int mid=(l+r)/2;
	rt[x].lch=totr+1;build(l,mid);
	rt[x].rch=totr+1;build(mid+1,r);
	push_up(x);
	return ;
}

LL query(int x,int l,int r)
{
	if(l<=rt[x].l&&rt[x].r<=r){
		return calc(x);
	}
	push_down(x);
	int mid=(rt[x].l+rt[x].r)/2;
	LL ret=0;
	if(l<=mid) ret+=query(rt[x].lch,l,r);
	if(r>=mid+1) ret+=query(rt[x].rch,l,r);
	push_up(x);
	return ret;
}
void modify(int x,int l,int r,int v)
{
	if(l<=rt[x].l&&rt[x].r<=r)
	{
		rt[x].light+=v;
		return ;
	}
	push_down(x);
	int mid=(rt[x].l+rt[x].r)/2;
	if(l<=mid)modify(rt[x].lch,l,r,v);
	if(r>=mid+1)modify(rt[x].rch,l,r,v);
	push_up(x);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		
	build(1,n);
	
	while(m--){
		int l,r;
		LL v;
		scanf("%d%d%lld",&l,&r,&v);
		modify(1,l,r,v);
		printf("%lld\n",query(1,l,r));
	}
	return 0;
}
