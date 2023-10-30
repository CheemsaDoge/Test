#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}
const int MAXN=1e5+1145;const int INF=2147483647ll;
struct Edge{int u,v,nxt;}edge[MAXN];
struct Point{int val,stick,num;}point[MAXN];
bool operator<(Point a,Point b){return a.val>b.val;}
int n,m,totr,ans=INF,wans=INF,num,a,b;bool single[MAXN];priority_queue<Point>po;Point u;
void add_edge(int u,int v){edge[++totr].u=u;edge[totr].v=v;point[v].stick++;point[u].stick++;}
inline void initialize()
{totr=0;ans=INF;wans=INF;memset(edge,0,sizeof(edge));memset(point,0,sizeof(point));
memset(single,0,sizeof(single));}
int main() {
		/*freopen("graph.in","r",stdin);freopen("graph.out","w",stdout);*/int T;read(T);while(T--){
		initialize();while(!po.empty()) po.pop();read(n),read(m);
		for(int i=1;i<=n;i++) read(point[i].val),point[i].num=i,po.push(point[i]);
		for(int i=1;i<=m;i++) read(a),read(b),add_edge(a,b);
		if(m%2==0) {printf("0\n");continue;}while(!po.empty()){num=po.top().num;u=point[num];
			if(u.stick%2) {ans=min(ans,u.val);single[u.num]=1;}po.pop();}
		for(int i=1;i<=m;i++) if((!single[edge[i].v])&&(!single[edge[i].u])) 
		wans=min(wans,point[edge[i].u].val+point[edge[i].v].val);
		printf("%d\n",min(ans,wans));}}
