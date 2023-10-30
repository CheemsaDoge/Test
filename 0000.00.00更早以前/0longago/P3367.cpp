#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4+1145;
inline int read()
{
    int s = 0,w = 1;
    char g = getchar();
    while(g<'0'||g>'9'){if(g=='-')w*=-1;g = getchar();}
    while(g>='0'&&g<='9'){s = s*10+g-'0';g = getchar();}
    return s*w;
}
int n,m;
int fa[MAXN];
int num[MAXN];
inline void Initialize()
{
	for(int i=1;i<=n;i++)	fa[i]=i,num[i]=1;
}
int backdate(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=backdate(fa[x]);
}
void mix(int x,int y)
{
	if(num[x]>num[y])	x+=y,y=x-y,x-=y;
	num[x]+=num[y];
	num[y]=num[x];
	fa[backdate(x)]=y;
	backdate(x);
}
int main()
{
	n=read();
	m=read();
	int operate;
	int a,b;
	Initialize();
	for(int i=1;i<=m;i++)
	{
		operate=read();
		a=read();
		b=read();
		if(operate==1)
			mix(a,b);
		else
			if(backdate(a)==backdate(b))
				printf("Y\n");
			else
				printf("N\n");
	}
}
