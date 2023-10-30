/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int n;int m;
struct EDGE{
	int u,v,val,nxt;
}edge[MAXM*3];
int head[MAXN],totr;
void add_edge(int u,int v,int w){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].val=w;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
int a,b,c;
bool vis[MAXN];
priority_queue<int>ans;
void dfs(int u,int res)
{
	vis[u]=1;
	if(u==n) {
		ans.push(-res);
		return ;
	}
	#define v edge[i].v
	for(int i=head[u];i;i=edge[i].nxt)
	{
		if(!vis[v]) {
			dfs(v,res+edge[i].val);
			vis[v]=false;
		}
	}
	vis[u]=false;
	#undef v
}
int main() {
	freopen("second.in","r",stdin);
	freopen("second.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	read(n);read(m);
	for(int i=1;i<=m;i++)
	{
		read(a);read(b);read(c);
		add_edge(a,b,c);
		add_edge(b,a,c);
	}
	dfs(1,0);
	int q=ans.top();
	ans.pop();
	while(q==ans.top()) ans.pop();
	write(-ans.top());
}
