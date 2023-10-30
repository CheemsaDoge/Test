#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=2e5+10;
int n,m,len;
int a[maxn],b[maxn];
int R[maxn]; 
int ans[maxn];
int st[maxn],ed[maxn],ed2[maxn];
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>57||ch<48)ch=getchar();
	do num=(num<<1)+(num<<3)+(ch^48),ch=getchar(); while(ch>47&&ch<58);
	return num;
}
struct lsh
{int id,x;}tmp[maxn];
bool lsh_cmp(lsh x,lsh y)
{return x.x<y.x;}
struct query
{int l,r,id;}q[maxn];
bool query_cmp(query x,query y)
{return (b[x.l]==b[y.l])?x.r<y.r:b[x.l]<b[y.l];}
void datain()
{
	n=read();
	len=sqrt(n); 
	for(int i=1;i<=n;i++)
	{
		tmp[i].x=read();
		tmp[i].id=i;
		b[i]=(i-1)/len+1;
	}
	for(int i=1;i<=b[n];i++)
	R[i]=(i==b[n])?n:len*i;
	m=read();
	for(int i=1;i<=m;i++)
	{
		q[i].l=read();q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+m+1,query_cmp);
}
void lsh() 
{
	sort(tmp+1,tmp+n+1,lsh_cmp);
	int pre=-1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(tmp[i].x!=pre)cnt++;
		a[tmp[i].id]=cnt; 
		pre=tmp[i].x;
	}
}
void work() 
{
	int block=0,tmp1=0,l=0,r=0;
	for(int i=1;i<=m;i++)
	{
		if(b[q[i].l]==b[q[i].r])
		{
			tmp1=0;
			for(int j=q[i].l;j<=q[i].r;j++)st[a[j]]=0;
			for(int j=q[i].l;j<=q[i].r;j++)
			{		
				if(!st[a[j]])st[a[j]]=j;
				tmp1=max(tmp1,j-st[a[j]]);
			}
			for(int j=q[i].l;j<=q[i].r;j++)st[a[j]]=0;
			ans[q[i].id]=tmp1;
			continue ;
		}
		int now=b[q[i].l]; 
		if(block!=now) 
		{
			tmp1=0;
			for(int j=l;j<=r;j++)st[a[j]]=ed[a[j]]=0;  
			l=R[now];
			r=l-1;
			block=now;
		}
		while(r<q[i].r)
		{
			r++;
			if(!st[a[r]])st[a[r]]=r;
			ed[a[r]]=r;
			tmp1=max(tmp1,r-st[a[r]]);
		}
		int p=l,tmp2=0;
		while(q[i].l<p)
		{
			p--;
			if(!ed2[a[p]])ed2[a[p]]=p; 
			tmp2=max(tmp2,max(ed[a[p]],ed2[a[p]])-p); 
		}
		while(p<l) 
		{
			ed2[a[p]]=0;
			p++;
		}
		ans[q[i].id]=max(tmp2,tmp1); 
	}
}
int main()
{
	datain(); 
	lsh();
	work();
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}
