#include <bits/stdc++.h>

using namespace std;
const int maxn=1e4+10;
int dis[maxn][15],vis[maxn][15],head[maxn];
int n,m,k,sum;
int start,last;
struct node
{
    int id,v,used;//used使用了几次免费券
    node() {}
    node(int id,int v,int used):id(id),v(v),used(used) {}
    bool  operator <(const node b) const
    {
        return v>b.v;
    }
};
//链式前向星构图
struct edge
{
    int to,next,w;
} edge[maxn<<1];

void add(int u,int v,int w)
{
    edge[++sum].to=v;
    edge[sum].next=head[u];
    edge[sum].w=w;
    head[u]=sum;
}

void dijkstra(int start)
{
    memset(dis,0x7f7f7f7f,sizeof(dis));
    priority_queue<node> q;
    q.push(node(start,0,0));
    dis[start][0]=0;
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        int u=t.id;
        int kk=t.used;
        if(vis[u][kk])continue;
        vis[u][kk]=1;
        for(int i=head[u]; i; i=edge[i].next)
        {
            int v=edge[i].to;
            int w=edge[i].w;
            //两种情况,用免费和不用免费
            //不用
            if(dis[v][kk]>dis[u][kk]+w)
            {
                dis[v][kk]=dis[u][kk]+w;
                q.push(node(v,dis[v][kk],kk));
            }
            //用免费券
            if(kk+1<=k&&dis[v][kk+1]>dis[u][kk]+0)
            {
                dis[v][kk+1]=dis[u][kk];
                q.push(node(v,dis[v][kk+1],kk+1));
            }
        }
    }
}


int main()
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("%d%d",&start,&last);
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    dijkstra(start);
    int ans=0x7f7f7f7f;
    for(int i=0;i<=k;i++)
    {
        ans=min(ans,dis[last][i]);
    }
    printf("%d\n",ans);
    return 0;
}
/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=3e5+1145;const int MAXN=450;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
//[[maybe_unused]]inline void _File(){
//	freopen("Begin.in","r",stdin);
//	freopen("Begin.out","w",stdout);
//}


int main(){
//	_File();
	
	return 0;
}

