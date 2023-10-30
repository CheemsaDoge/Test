#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define MAXN 50010
#define MAXM 200010

struct node
{
    int from,to,dis;
} edge[MAXM<<1];
int head[MAXN<<1],cnt,n,m,dist[MAXN],home[10];
int dis1[8][8],minn=INT_MAX,pre[MAXN];
bool vis[MAXN];

template< typename T >inline void read(T &x)
{
    x=0;
    int f=1;
    char c=getchar();
    for(; !isdigit(c); c=getchar()) if(c=='-') f=-1;
    for(; isdigit(c); c=getchar()) x=((x<<3)+(x<<1)+(c^48));
    x*=f;
}
template< typename T >inline void write(T x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void add(int from,int to,int dis)
{
    edge[++cnt].from=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}
inline void Dij(int s)   //Dij板子
{
    priority_queue< pair< int,int > >q;
    memset(vis,0,sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int now=q.top().second;
        q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(ri i=head[now]; i; i=edge[i].from)
        {
            int v=edge[i].to;
            if(dist[v]>dist[now]+edge[i].dis)
            {
                dist[v]=dist[now]+edge[i].dis;
                if(!vis[v])
                {
                    q.push(make_pair(-dist[v],v));
                }
            }
        }
    }

    //将最短路得到的结果转化为tsp模型所需的邻接矩阵
    for(ri i=1; i<=6; ++i)
        dis1[pre[s]][i]=dis1[i][pre[s]]=min(dis1[i][pre[s]],dist[home[i]]);
    //这里需要注意要将原来的点编号转化为邻接矩阵中点的编号
}
inline void dfs(int now,int dis,int rest)   //通过爆搜解决tsp问题
{
    if(rest==0)
    {
        if(dis<minn)
        {
            minn=dis;
        }
        return;
    }
    if(dis>minn) return;//小剪枝
    for(ri i=1; i<=6; ++i)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(i,dis+dis1[now][i],rest-1);
            vis[i]=0;
        }
    }

}

int main()
{
	freopen("visit.in","r",stdin);
	freopen("visit.out","w",stdout);
    read(n);
    read(m);
    home[1]=1;
    pre[1]=1;
    for(ri i=2; i<=6; ++i) read(home[i]),pre[home[i]]=i;
    int u,v,t;
    for(ri i=1; i<=m; ++i)
    {
        read(u);
        read(v);
        read(t);
        add(u,v,t);
        add(v,u,t);
    }
    memset(dis1,0x3f,sizeof(dis1));
    for(ri i=1; i<=6; ++i)//这里其实不需要跑6遍，5遍足够了
        Dij(home[i]);
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    dfs(1,0,5);
    write(minn);
}
