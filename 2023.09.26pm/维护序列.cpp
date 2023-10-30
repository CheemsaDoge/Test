#include<iostream>
#define lz k<<1,l,mid
#define rz k<<1|1,mid+1,r
using namespace std;
typedef long long ll;
const int N=1e5+7;
ll f[N*4];
ll n,m,p;
struct tt
{
	ll sum;
	ll add;
    ll val;
}e[N*4];
void buildtree(int k,int l,int r)
{
	e[k].val=1;
	e[k].add=0;
	if(l==r)
	{
		e[k].sum=f[l];
		return;
	}
	int mid=(l+r)>>1;
	buildtree(lz);
	buildtree(rz);
	e[k].sum=e[k<<1].sum+e[k<<1|1].sum;
	return ;
}
void pushdown(int k,int o)//o表示 区间len 
{
	int kl=k<<1,kr=k<<1|1;
	e[kl].sum=(e[kl].sum*e[k].val+e[k].add*(o-(o>>1)))%p;
	e[kr].sum=(e[kr].sum*e[k].val+e[k].add*(o>>1))%p;
	e[kl].val=(e[kl].val*e[k].val)%p;
	e[kr].val=(e[kr].val*e[k].val)%p;
	
	e[kl].add=(e[kl].add*e[k].val+e[k].add)%p;
	e[kr].add=(e[kr].add*e[k].val+e[k].add)%p;
	e[k].val=1;
	e[k].add=0;
	return;
}
void add(int k,int l,int r,int x,int y,int w)//x~y add w 
{
	if(x<=l&&y>=r)
	{
		e[k].add=(e[k].add+w)%p;
		e[k].sum=(e[k].sum+(r-l+1)*w)%p;
		return ;
	}
	pushdown(k,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)
		add(lz,x,y,w);
	if(y>mid)
		add(rz,x,y,w);
	e[k].sum=(e[k<<1].sum+e[k<<1|1].sum)%p;
	return;
}
void mul(int k,int l,int r,int x,int y,int w)
{
	if(x<=l&&y>=r)
	{
		e[k].val=(e[k].val*w)%p;
		e[k].add=(e[k].add*w)%p;
		e[k].sum=(e[k].sum*w)%p;
		return ;
	}
	pushdown(k,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)
		mul(lz,x,y,w);
	if(y>mid)
		mul(rz,x,y,w);
	e[k].sum=(e[k<<1].sum+e[k<<1|1].sum)%p;
	return ;
}

ll query(int k,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)
	{
		return e[k].sum%p;
	}
	int mid=(l+r)>>1;
	pushdown(k,r-l+1);
	ll temp=0;
	if(x<=mid)
	temp=(temp+query(lz,x,y));
	if(y>mid)
	temp=(temp+query(rz,x,y));
	e[k].sum=(e[k<<1].sum+e[k<<1|1].sum)%p;
	return temp%p;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++) cin>>f[i];
	buildtree(1,1,n);//建树 
	cin>>m;
	while(m--)
	{
		int a,b,c,d;
		cin>>a>>b>>c;
		if(a==1)
		{
			cin>>d;
			mul(1,1,n,b,c,d);
		}
		else if(a==2)
		{
			cin>>d;
			add(1,1,n,b,c,d);
		}
		else
		{
			cout<<query(1,1,n,b,c)<<endl;
		}
	}
	return 0;
 } 
