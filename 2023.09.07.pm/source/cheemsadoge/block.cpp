/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=2e6+114514;const int INF=1e8+1;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("NOT POSSIBLE")
#define pnw puts("NOT UNIQUE")
/*---------------------------------pre------------------------------------*/
struct Edge{
	int v,w,nex;
}edge[MAXN];
int tote=0;
int head[MAXN];
void Add_Edge(int u,int v,int w)
{
	tote++;
	edge[tote].v=v;
	edge[tote].w=w;
	edge[tote].nex=head[u];
	head[u]=tote;
}

int dist[MAXN],n,sec[MAXN];
struct Node{
	int dist;
	int num;
};
bool operator <( Node a,Node b) {return a.dist>b.dist;}
priority_queue<Node>q;


int dijkstra(int S,int T){
	for(int i=1;i<=n+10000;i++)
		dist[i]=sec[i]=INF;
	dist[S]=0;
	Node u;
	u.num=S;
	u.dist=0;
	q.push(u);
	while(!q.empty())
	{
		u=q.top();q.pop();
		int d=u.dist;
		if(sec[u.num]<d) continue;
        Node t;
		for(int i=head[u.num];i;i=edge[i].nex)
		{
			int v=edge[i].v;
			int d2=d+edge[i].w;
            if(dist[v]>d2){
                swap(dist[v],d2);
                t.dist=dist[v];
                t.num=v;
                q.push(t);
            }
            if(sec[v]>d2&&dist[u.num]<d2){
                sec[v]=d2;
                t.dist=sec[v];
                t.num=v;
				q.push(t);
            }

		}
	}
	return sec[T];
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int m;
	int u,v,w;
	read(n);read(m);
	for(int i=1;i<=m;i++)
	{
		read(u),read(v),read(w);
		Add_Edge(u,v,w);
		Add_Edge(v,u,w);
	}
	write(dijkstra(1,n));
	return 0;
}
