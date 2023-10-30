/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn putchar('N')
#define py putchar('Y')
/*---------------------------------pre------------------------------------*/
struct EDGE{
	int u,v,val,nxt;
	bool tr;
}edge[MAXM*4];
int head[MAXN],totr;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
int n,s;
int fa[MAXN][30],lg[MAXN];
int dep[MAXN];
void dfs(int u,int fath)
{
	#define v edge[i].v
	fa[u][0]=fath;
	dep[u]=dep[fath]+1;
	for(int i=1;i<=lg[dep[u]];++i)
        fa[u][i] = fa[fa[u][i-1]][i-1];
    for(int i=head[u];i;i=edge[i].nxt)
        if(v!=fath) dfs(v,u);
	#undef v
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y])
        x = fa[x][lg[dep[x]-dep[y]] - 1];
    if(x == y) return x;
    for(int k = lg[dep[x]] - 1; k >= 0; --k)
        if(fa[x][k] != fa[y][k])
            x = fa[x][k], y = fa[y][k];
    return fa[x][0];
}
bool pd(int a,int b,int c,int d)
{
	int ab=LCA(a,b);
	int cd=LCA(c,d);
	if(((dep[ab]>=dep[cd])&&((LCA(ab,c)==ab)||(LCA(ab,d)==ab)))||(dep[cd]>=dep[ab])&&(((LCA(cd,a)==cd)||(LCA(cd,b)==cd)))) return true;
	return false;
}
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int m,u,v,a,b,c,d;
	read(n);read(m);
	for(int i=1;i<n;i++)
	{
		read(u),read(v);
		add_edge(u,v),add_edge(v,u);
	}
    for(int i=1;i<=n;++i) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		read(a),read(b),read(c),read(d);
		if(pd(a,b,c,d)) py;
		else pn;
		pc;
	}
	
}
