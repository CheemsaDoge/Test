#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1145;
inline int read()
{
    int s = 0,w = 1;
    char g = getchar();
    while(g<'0'||g>'9'){if(g=='-')w*=-1;g = getchar();}
    while(g>='0'&&g<='9'){s = s*10+g-'0';g = getchar();}
    return s*w;
}
int tot=0;
int x[MAXN],y[MAXN],r[MAXN];
bool l[MAXN],sr[MAXN],u[MAXN],d[MAXN];
int n,m,p;
int fa[MAXN];
int num[MAXN];
int Mandela_Range(int x1,int y1,int x2,int y2)
{
	int rangex=abs(x1-x2);
	int rangey=abs(y1-y2);
	return sqrt(rangex*rangex-rangey*rangey);
}
inline void Initialize(int n)
{
	for(int i=1;i<=n;i++)	fa[i]=i,num[i]=1;
}
int backdate(int x)
{
	if(fa[x]==x)
		return x;
	fa[x]=backdate(fa[x]);
	l[fa[x]]=l[fa[x]]|l[x];
	sr[fa[x]]=sr[fa[x]]|sr[x];
	u[fa[x]]=u[fa[x]]|u[x];
	d[fa[x]]=d[fa[x]]|d[x];
	return fa[x];
}
void mix(int x,int y)
{
	if(num[x]>num[y])	x+=y,y=x-y,x-=y;
	num[x]+=num[y];
	num[y]=num[x];
	fa[backdate(x)]=y;
	backdate(x);
}
void Mix_round(int R1,int x1,int y1,int r1,int R2,int x2,int y2,int r2)
{
	int range=Mandela_Range(x1,y1,x2,y2);
	if(range<=r1+r2)
		mix(R1,R2);
	return ;
}
int main()
{
	freopen("forest.in","r",stdin);
	freopen("forest.out","w",stdout);
	/*printf("N");*/
	m=read();
	n=read();
	p=read();
	Initialize(p);
	for(int i=1;i<=p;i++)
	{
		tot++;
		x[tot]=read();
		y[tot]=read();
		r[tot]=read();
		l[tot]=x[tot]-r[tot]<=1?1:0;
		sr[tot]=x[tot]+r[tot]>=n?1:0;
		u[tot]=y[tot]+r[tot]>=m?1:0;
		d[tot]=y[tot]-r[tot]<=0?1:0;
		for(int j=1;j<i;j++)
			Mix_round(j,x[j],y[j],r[j],i,x[i],y[i],r[i]);
	}
	for(int i=1;i<=p;i++)
	{
		backdate(i);
//		printf("i%d fa%d\nl%d r%d u%d d%d\n",i,fa[i],l[fa[i]],sr[fa[i]],u[fa[i]],d[fa[i]]);
		if((l[fa[i]]&&sr[fa[i]])||(l[fa[i]]&&d[fa[i]])||(d[fa[i]]&&u[fa[i]])||(sr[fa[i]]&&u[fa[i]]))
		{
			printf("N");
			return 1;
		}
	}
	printf("S");
}
