#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<set>
#include<time.h>
using namespace std;
typedef long long LL;
inline int rei()
{
  int x=0,f=1;
  char c=getchar();
  while((c>'9'||c<'0')&&c!='-')
    c=getchar();
  if(c=='-')
    f=-1,c=getchar();
  while(c>='0'&&c<='9')
    x=x*10+c-48,c=getchar();
  return x*f;
}
void wri(int x)
{
  if(x<0)
    putchar('-'),x=-x;
  if(x>9)
    wri(x/10);
  putchar(x%10+48);
}
int n,m;
int head[100005],tot,dep[100005];
int cnt,fa[100010];
bool Us[300005];
LL Min,Ans=10000000000000000ll;
struct LINE
{
  int to,pre,v;
}line[200005];
struct LINE2
{
  int x,y,v;
}line2[300005];
struct BEIZENG
{
  int Ancestor,Longest,Second_Longest;
  BEIZENG()
  {
    Longest=0,Second_Longest=-100;
  }
}F[100005][22];
bool cmp(LINE2 A,LINE2 B)
{
  return A.v<B.v;
}
void Edge(int st,int ed,int v)
{
  tot++;
  line[tot].to=ed,line[tot].v=v;
  line[tot].pre=head[st];
  head[st]=tot;
}
int Find(int x)
{
  if(x==fa[x])
    return x;
  fa[x]=Find(fa[x]);
  return fa[x];
}
void Kru()
{
  int u,v;
  for(int i=1;i<=n;i++)
    fa[i]=i;
  for(int i=1;i<=m;i++)
  {
    u=Find(line2[i].x);
    v=Find(line2[i].y);
    if(u==v)
      continue;
    Us[i]=true;
    fa[u]=v;
    Edge(line2[i].x,line2[i].y,line2[i].v);
    Edge(line2[i].y,line2[i].x,line2[i].v);
    Min+=line2[i].v;
    cnt++;
    if(cnt==n-1)
      return;
  }
}
void D(int x,int f)
{
  F[x][0].Ancestor=f;
  dep[x]=dep[f]+1;
  for(int i=head[x];i;i=line[i].pre)
  {
    if(line[i].to==f)
      continue;
    F[line[i].to][0].Longest=line[i].v;
    D(line[i].to,x);
  }
}
void Work(int x,int y,int len)
{
  int lon=0,slo=-1,jum=0;
  if(dep[x]<dep[y])
    swap(x,y);
  int cc=dep[x]-dep[y];
  while(cc)
  {
    if(cc&1)
    {
      slo=max(slo,F[x][jum].Second_Longest);
  	  if(lon>F[x][jum].Longest)
  	    slo=max(slo,F[x][jum].Longest); 
  	  else if(lon<F[x][jum].Longest)
  	    slo=max(lon,slo),lon=F[x][jum].Longest;
      x=F[x][jum].Ancestor;
	}
    jum++;
    cc>>=1;
  }
  if(x==y)
  {
    if(len!=lon)
      Ans=min(Ans,Min-lon+len);
    else if(slo>0)
      Ans=min(Ans,Min-slo+len);
    return;
  }
  for(int i=20;i>=0;i--)
  {
    if(F[x][i].Ancestor==F[y][i].Ancestor)
      continue;
    slo=max(slo,F[x][i].Second_Longest);
  	if(lon>F[x][i].Longest)
  	  slo=max(slo,F[x][i].Longest); 
  	else if(lon<F[x][i].Longest)
  	  slo=max(lon,slo),lon=F[x][i].Longest;
    x=F[x][i].Ancestor;
    slo=max(slo,F[y][i].Second_Longest);
  	if(lon>F[y][i].Longest)
  	  slo=max(slo,F[y][i].Longest); 
  	else if(lon<F[y][i].Longest)
  	  slo=max(lon,slo),lon=F[y][i].Longest;
    y=F[y][i].Ancestor;
  }
  slo=max(slo,F[x][0].Second_Longest);
  if(lon>F[x][0].Longest)
  	slo=max(slo,F[x][0].Longest); 
  else if(lon<F[x][0].Longest)
  	slo=max(lon,slo),lon=F[x][0].Longest;
  x=F[x][0].Ancestor;
  slo=max(slo,F[y][0].Second_Longest);
  if(lon>F[y][0].Longest)
  	slo=max(slo,F[y][0].Longest); 
  else if(lon<F[y][0].Longest)
  	slo=max(lon,slo),lon=F[y][0].Longest;
  x=F[y][0].Ancestor;
  if(len!=lon)
    Ans=min(Ans,Min-lon+len);
  else 
    Ans=min(Ans,Min-slo+len);
}
int main()
{
	freopen("tree.in","r",stdin);
freopen("tree.out","w",stdout);
  n=rei(),m=rei();
  for(int i=1;i<=m;i++)
    line2[i].x=rei(),line2[i].y=rei(),line2[i].v=rei();
  sort(line2+1,line2+1+m,cmp);
  Kru();
  D(1,1);
  for(int i=1;i<=20;i++)
    for(int j=1;j<=n;j++)
    {
      F[j][i].Ancestor=F[F[j][i-1].Ancestor][i-1].Ancestor;
      F[j][i].Longest=max(F[j][i-1].Longest,F[F[j][i-1].Ancestor][i-1].Longest);
      if(F[j][i-1].Longest==F[F[j][i-1].Ancestor][i-1].Longest)
        F[j][i].Second_Longest=max(F[j][i-1].Second_Longest,F[F[j][i-1].Ancestor][i-1].Second_Longest);
	  else
	    F[j][i].Second_Longest=min(F[j][i-1].Longest,F[F[j][i-1].Ancestor][i-1].Longest);
	}
  for(int i=1;i<=m;i++)
  {
    if(Us[i])
      continue;
    Work(line2[i].x,line2[i].y,line2[i].v);
  }
  cout<<Ans;
  return 0;
}
