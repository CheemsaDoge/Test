#include<bits/stdc++.h>
using namespace std;
const int MAXN = 6010;
int n;
int r[MAXN];
struct Edge
{
	int from,to,nxt,val;
}E[MAXN*3];
int head[MAXN],tot;
int dp[MAXN][2];
void Edge_add(int x,int y)
{
	++tot;
	E[tot].from=x;
	E[tot].to=y;
	E[tot].nxt=head[x];
	head[x]=tot;
}
void dfs(int x)
{
	dp[x][0]=0;
	dp[x][1]=r[x];
	for(int i=head[x];i;i=E[i].nxt)
	{
		int v=E[i].to;
		dfs(v);
		dp[x][0]+=max(dp[v][0],dp[v][1]);
		dp[x][1]+=dp[v][0];
	}
}
int vis[MAXN],rt;
int main()
{
	freopen("boss.in","r",stdin); 
	freopen("boss.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&r[i]);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Edge_add(y,x);
		vis[x]=1;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			rt=i;
			break;
		}
	dfs(rt);
	cout<<max(dp[rt][0],dp[rt][1]);
	return 0;
 } 
 /*
 7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
 */
