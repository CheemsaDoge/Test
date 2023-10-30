#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
const int MAXN=400010;
int n;
int hd[MAXN],tot,to[MAXN],pre[MAXN];
int f[MAXN];
LL sum,maxans,w[MAXN];
const LL p=10007;
void Edge(int x,int y)
{
  tot++;
  to[tot]=y;
  pre[tot]=hd[x];
  hd[x]=tot;
}
void dfs(int x)
{
  LL xsum=0,mw=0;
  for(int i=hd[x];i;i=pre[i])
  {
    if(to[i]==f[x])
      continue;
    f[to[i]]=x;
    dfs(to[i]);
    sum+=xsum*w[to[i]]%p,sum%=p;
    maxans=max(maxans,mw*w[to[i]]);
    xsum+=w[to[i]],xsum%=p;
    mw=max(mw,w[to[i]]);
  }
  maxans=max(maxans,w[f[x]]*mw);
  sum+=xsum*w[f[x]]%p,sum%=p;
}

int main()
{
  freopen("link.in","r",stdin);
  freopen("link.out","w",stdout);
  scanf("%d",&n);
  int u,v;
  for(int i=1;i<n;i++)
  {
  	scanf("%d%d",&u,&v);
  	Edge(u,v),Edge(v,u);
  }
  for(int i=1;i<=n;i++)
  	scanf("%d",&w[i]);
  dfs(1);
  printf("%lld %lld",maxans,(sum<<1ll)%p);
  return 0;
}
