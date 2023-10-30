#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=3010,maxm=30010;
const double eps=1e-11;
struct edge{int from,v;double w;}e[maxm];
int n,m,first[maxn],tot=0;
double d[maxn],w[maxm];
bool vis[maxn],flag;
void insert(int u,int v,double w)
{tot++;e[tot].v=v;e[tot].w=w;e[tot].from=first[u];first[u]=tot;}
void spfa(int x)
{
    vis[x]=1;
    for(int i=first[x];i;i=e[i].from)
     if(!flag&&d[e[i].v]>d[x]+e[i].w)
      {
          if(vis[e[i].v])
           {
               flag=1;
               break;
           }
          d[e[i].v]=d[x]+e[i].w;
          spfa(e[i].v);
      }
    vis[x]=0;
}
int main()
{
	freopen("nagative.in","r",stdin);
	freopen("nagative.out","w",stdout); 
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
     {
         int u,v;
         scanf("%d%d%lf",&u,&v,&w[i]);
         insert(u,v,w[i]);
     }
    double l=-10000000,r=10000000;
    while(r-l>eps)
     {
         double mid=(l+r)/2;
         flag=0;
         memset(d,0,8*(n+1));
         memset(vis,0,(n+1));
         for(int i=1;i<=tot;i++)e[i].w=w[i]-mid;
         for(int i=1;i<=n;i++)if(!flag)spfa(i);
         if(flag)r=mid;else l=mid;
     }
    printf("%.8lf",l);
    return 0;
}
