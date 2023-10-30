#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ri register int
const int MAXN=1e6+1145;
int maxn=0;
int n,m,k;
bool a[9][9];
inline void dfs(int n,int m,int dep)
{
	maxn=max(maxn,dep);
	for(ri i=1;i<=n;i++)
	{
		for(ri j=1;j<=m;j++)
		{
			if(!a[i][j])
				continue;
			if(!a[i-1][j]&&i-1>0&&a[i+1][j])//up
			{
				a[i-1][j]=1;a[i][j]=0;a[i+1][j]=0;
				dfs(n,m,dep+1);
				a[i-1][j]=0;a[i][j]=1;a[i+1][j]=1;
			}
			if(!a[i+1][j]&&i+1<=n&&a[i-1][j])//down
			{
				a[i+1][j]=1;a[i][j]=0;a[i-1][j]=0;
				dfs(n,m,dep+1);
				a[i+1][j]=0;a[i][j]=1;a[i-1][j]=1;
			}
			if(!a[i][j-1]&&j-1>0&&a[i][j+1])//left
			{
				a[i][j-1]=1;a[i][j]=0;a[i][j+1]=0;
				dfs(n,m,dep+1);
				a[i][j-1]=0;a[i][j]=1;a[i][j+1]=1;
			}
			if(!a[i][j+1]&&j+1<=m&&a[i][j-1])//right
			{
				a[i][j+1]=1;a[i][j]=0;a[i][j-1]=0;
				dfs(n,m,dep+1);
				a[i][j+1]=0;a[i][j]=1;a[i][j-1]=1;
			}
		}
	}
}
int x,y;
int main()
{
	freopen("halma.in","r",stdin);
	freopen("halma.out","w",stdout);
	read(n);read(m);read(k);
	for(ri i=1;i<=k;i++)
	{
		read(x);read(y);
		a[x][y]=1;
	}
	dfs(n,m,0);
	printf("%d",k-maxn);
}
