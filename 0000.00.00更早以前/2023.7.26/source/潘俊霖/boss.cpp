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
const int MAXN=2e4+1145ll;
#define ll long long
#define ri register int
#define rl register long long
struct Edge {
	int u,v,nxt;
} edge[MAXN];
int val[MAXN];
int head[MAXN],totr=0;
void add_edge(int u,int v) {
	edge[++totr].nxt=head[u];
	head[u]=totr;
	edge[totr].u=u;
	edge[totr].v=v;
}
bool vis[MAXN];
ll f[MAXN][3];
void calc(int k) {
#define  v edge[i].v
	vis[k] = 1;
	for (int i=head[k];i;i=edge[i].nxt) {
		if (vis[v]) continue;
		calc(v);
		f[k][1] += f[v][0];
		f[k][0] += max(f[v][0], f[v][1]);
	}
	return;
#undef v
}
int op,t,x,y,z,n;
int is_head[MAXN];
int main() {
	freopen("boss.in","r",stdin);
	freopen("boss.out","w",stdout);
	read(n);
	for(int i=1; i<=n; i++) read(f[i][1]);
	for(int i=1; i<n; i++) {
		read(x);read(y);
		add_edge(y,x);
		is_head[x]=-1;
		is_head[y]=(is_head[y]==-1)?-1:1;
	}
	ri i;
	for(i=1;i<=n;i++)
		if(is_head[i]==1)
		{
			calc(i);
			break;
		}
		if(n==1)
		{
			printf("%lld",f[1][1]);
			return 0;
		}
	printf("%lld",max(f[i][0],f[i][1]));
}






