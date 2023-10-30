#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fuck puts("fuck");
const ll maxn=2e5+100;
const ll maxm=1e6+100;
template <typename T> inline void read (T &x)
{
	x=0;
	int f=0;
	char c=getchar();
	for(; !isdigit(c); c=getchar()) f|=(c=='-');
	for(; isdigit(c); c=getchar()) x=((x<<3)+(x<<1)+(c^48));
	x=(f?-x:x);
}
template <typename T> inline void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10^'0');
}
int n,m,ha,zuo,you,p,cnt;
int ans[maxn],st[maxn],en[maxn],belong[maxn];
int temp[maxn],clear[maxn];
struct node
{
	int num,hash,val;
}a[maxn];
struct Node
{
	int l,r,num;
}wyy[maxn];
bool cmp1(node x,node y)
{
	return x.val<y.val;
}
bool cmp2(node x,node y)
{
	return x.num<y.num;
}
bool cmp3(Node x,Node y)
{
	return belong[x.l]==belong[y.l]?x.r<y.r:x.l<y.l;
}
int force(int l,int r)
{
	int ret=0;
	for(int i=l;i<=r;i++) temp[a[i].hash]=0;
	for(int i=l;i<=r;i++) 
	{
		if(!temp[a[i].hash]) temp[a[i].hash]=i;
		else ret=max(ret,i-temp[a[i].hash]);
	}
	return ret;
}
int main()
{
	freopen("rage.in","r",stdin);
	freopen("rage.out","w",stdout);
	read(n);
	p=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i].val);
		a[i].num=i;
		belong[i]=(i-1)/p+1;
	}
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++)
	{
		if(a[i].val!=a[i-1].val) a[i].hash=++ha;
		else a[i].hash=ha;
	}
	sort(a+1,a+1+n,cmp2);
	read(m);
	for(int i=1;i<=m;i++)
	{
		read(wyy[i].l);
		read(wyy[i].r);
		wyy[i].num=i;
	}
	sort(wyy+1,wyy+1+m,cmp3);
	for(int i=1,j=1;j<=belong[n];j++)
	{
		int edge=min(n,j*p),l=edge+1,r=edge,now=0;
		cnt=0;
		for(;belong[wyy[i].l]==j;i++)
		{
			if(belong[wyy[i].r]==j)
			{
				ans[wyy[i].num]=force(wyy[i].l,wyy[i].r);
			}
			else
			{
				while(r<wyy[i].r)
				{
					++r;
					en[a[r].hash]=r;
					if(!st[a[r].hash]) st[a[r].hash]=r,clear[++cnt]=a[r].hash;
					now=max(now,r-st[a[r].hash]);
				}
				int copy=now;
				while(l>wyy[i].l)
				{
					--l;
					if(en[a[l].hash]) now=max(now,en[a[l].hash]-l);
					else en[a[l].hash]=l;
				}
				ans[wyy[i].num]=now;
				while(l<=edge)
				{
					if(en[a[l].hash]==l) en[a[l].hash]=0;
					++l;
				}
				now=copy;
			}
			
		}
		for(int k=1;k<=cnt;k++)
		{
			st[clear[k]]=en[clear[k]]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		write(ans[i]);
		putchar('\n');
	}
	return 0;
}

