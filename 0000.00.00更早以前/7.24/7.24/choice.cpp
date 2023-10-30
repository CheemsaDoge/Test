#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
#define ri register int
int n,q,x,b,c;
struct edge {
	int v,val,next;
} e[6005];
int head[6005],cnt, f[6005][2], ans, is_h[6005], vis[6005];
void addedge(int u, int v,int val) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	e[cnt].val=val;
	head[u] = cnt;
}
void calc(int k,int last,int from) {
	vis[k] = 1;
	f[k][last]=e[from].val;
	if(last==q)	return;
	for (ri i = head[k]; i; i = e[i].next) {
		if (vis[e[i].v]) continue;
		calc(e[i].v,last+1,i);
	}
	ri sum;
	for(ri j=last+1;j<=q;j++)
	{
		for(ri p=last+1;p<=j;p++)
		{
			sum=0;
			ri i=head[k];
			sum+=f[e[i].v][p];
			i=e[i].next;
			sum+=f[e[i].v][last+j-p];
			f[k][j]=max(f[k][j],sum);
		}
		f[k][j]+=e[from].val;
		printf("sss%d %d\n",k,f[k][j]);
	}
	f[k][last]=e[from].val;
	return;
}
int a[200][200];
void dfs(int u,int fa)
{
	for(int i=1;i<=n;i++)
		if(a[u][i]&&i!=fa)addedge(u,i,a[u][i]),dfs(i,u),is_h[u]=1;
}
#define ll long long
#define ri register int
#define rl register long long
const int MAXN=1e6+1145;
int main() {
//	freopen("choice.in","r",stdin);
//	freopen("choice.out","w",stdout);
	scanf("%d%d", &n,&q);
	for (int i = 1; i <= n-1; i++) scanf("%d%d%d", &x,&b,&c),a[x][b]=c,a[b][x]=c;//linjiejuzhen
	dfs(1,0);//add_edge
	calc(1,0,0);
	printf("%lld",f[1][q]);
}


















//OI-er==Æ»¹ûÊÇ°É
