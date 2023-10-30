#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int maxn=1e5+5;;

int n,m;
int fa[maxn];
int dist1[510][510],dist2[510][510];
struct node
{
    int a,b,w;
    bool flag;
    bool operator<(const node & x)const 
    {
        return w<x.w;
    }
}edge[maxn];

int head[maxn],idx;

struct star
{
    int to;
    int w;
    int nxt;
}e[maxn*2];

void init()
{
    for(int i=0;i<=n;i++) fa[i]=i;
    return ;
}
void add(int a,int b,int c) 
{
    idx++;
    e[idx].to=b;
    e[idx].w=c;
    e[idx].nxt=head[a];
    head[a]=idx;
}

inline int find(int x) 
{
    return fa[x]!=x?fa[x]=find(fa[x]):fa[x];
} 

void dfs(int u,int fu,int maxd1,int maxd2,int d1[],int d2[]) 
{ 
    d1[u]=maxd1;
    d2[u]=maxd2; 
    for (int i=head[u];~i;i=e[i].nxt) 
    {
        int To=e[i].to;
        int W=e[i].w;
        if(To!=fu) 
        {
            int td1=maxd1;
            int td2=maxd2;
            if(W>td1) 
            {
                td2=td1;
                td1=W;
            }
            else if(W>td2&&W<td1)
            {
                td2=W;
            }
            dfs(To,u,td1,td2,d1,d2); 
        }
    }
}

int main() 
{
    scanf("%d %d",&n,&m);
    memset(head,-1,sizeof(head));

    for(int i=1;i<=m;i++) 
    {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        edge[i].a=a;
        edge[i].b=b;
        edge[i].w=w;
        edge[i].flag=0;
    }

    sort(edge+1,edge+1+m);
    init();
    LL sum=0;
    for(int i=1;i<=m;i++) 
    {
        int a=edge[i].a;
        int b=edge[i].b;
        int w=edge[i].w;
        if(find(a)!=find(b)) 
        {
            fa[find(a)]=find(b);
            sum+=w;
            add(a,b,w);
            add(b,a,w);
            edge[i].flag=1;
        }
    }

    for (int i=1;i<=n;i++)
        dfs(i,-1,0,0,dist1[i],dist2[i]);
    LL res=1e18;
    for(int i=1;i<=m;i++)
    {
        if(edge[i].flag==0)
        {
            int a=edge[i].a;
            int b=edge[i].b;
            int w=edge[i].w;
            LL t;
            if(w>dist1[a][b])  t=sum+w-dist1[a][b];
            else if(w>dist2[a][b]) t=sum+w-dist2[a][b];
            res=min(res,t);
        }
    }
    printf("%lld\n", res);
    return 0;
}
