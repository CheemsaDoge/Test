#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
inline int lowbit(int x)
{
	return (x&(-x));
}
const int MAXN=1e6+1145;
struct segtree{
	int l,r;
	long long sum,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
}tree[MAXN*4];
int a[MAXN],n,m;
int mid;
void build(int p,int l,int r)
{
	mid = (l+r)/2;
	l(p)=l;
	r(p)=r;
	if(l==r){
		sum(p)=a[l];
		return ;
	}
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p)=sum(p*2)+sum(p*2+1);
}
void spread(int p)
{
	if(add(p)){
		sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);
		sum(p*2+1)+=add(r(p*2+1)-l(p*2+1)+1);
		add(p*2)+=add(p);
		add(p*2+1)+add(p);
		add(p)=0;
	}
}
void change(int p,int l,int r,int d)
{
	if(l<=l(p)&&r>=r(p)){
		sum(p)+=(long long)d*(r(p)-l(p)+1);
		add(p)+=d;
		return ;
	}
	spread(p);
	int mid=(l(p)+r(p))/2;
	if(l<=mid)change(p*2,l,r,d);
	if(r>mid)change(p*2+1,l,r,d);
	sum(p)=sum(p*2)+sum(p*2+1);
}
long long ask(int p,int l,int r)
{
	if(l<=l(p)&&r>r(p))	return sum(p);
	spread(p);
	int mid=(l(p)+r(p))/2;
	long long val=0;
	if(l<=mid) val+=ask(p*2,l,r);
	if(r>mid)	val+=ask(p*2+1,l,r);
	return val;
}
int main()
{
	freopen("sgtree.in","r",stdin);
	freopen("sgtree.out","w",stdout);
	read(n);
	read(m);
	int op;
	int x,y;
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=m;i++)
	{
		read(op);
		read(x);
		read(y);
		if(op==1)
			change(1,x,y,1);
		else
			printf("%lld\n",ask(1,x,y));
	}
}
