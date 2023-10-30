/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void sread(T &x) {T ans;ans=getchar()-'0';x=ans;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXN=5e3+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n')
/*---------------------------------pre------------------------------------*/
int n,m,t,u,v;
struct EDGE{
	int u,v,val,nxt;
	bool tr;
}edge[MAXN*4];
int head[MAXN],totr;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
int dep[MAXN];bool vis[MAXN];
stack<int>sta;
bool dfs(int u,int deep)
{
	vis[u]=1;dep[u]=deep;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		#define v edge[i].v
		if(!vis[v]) dfs
		
		#undef v
	}
}
//int cnt;
bool s[MAXN][MAXN];
int main()
{
	read(n);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n+1;j++) 
		{
			sread(s[i][j]);
			if(s[i][j]&&j<=n) add_edge(i,j);
		}
//	for(int i=1;i<=n;i++) {for(int j=1;j<=n;j++) write(edge[i][j]); pc;}

	
//	Initialize();
}
