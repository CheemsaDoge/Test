#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
inline int rei()
{
  int f=1,x=0;
  char c=getchar();
  while((c<'0'||c>'9')&&c!='-')
    c=getchar();
  if(c=='-')
    f=-1,c=getchar();
  while(c>='0'&&c<='9')
    x=x*10+c-'0',c=getchar();
  return x*f;
}
inline LL rel()
{
  LL f=1,x=0;
  char c=getchar();
  while((c<'0'||c>'9')&&c!='-')
    c=getchar();
  if(c=='-')
    f=-1,c=getchar();
  while(c>='0'&&c<='9')
    x=x*10+c-'0',c=getchar();
  return x*f;
}
void wri(int x)
{
  if(x<0)
    putchar('-'),x=-x;
  if(x>9)
    wri(x/10);
  putchar(x%10+'0');
}
void wrl(LL x)
{
  if(x<0)
    putchar('-'),x=-x;
  if(x>9)
    wrl(x/10);
  putchar(x%10+'0');
}
int lowbit(int x)
{
  return x&(-x);
}
struct Dee
{
  int num,val;	
}a[100010];
int n,c[100010];
long long bit1[100010],bit2[100010],ans,ret;
void Add1(int Xh,LL x)
{
  for(;Xh<=n;Xh+=lowbit(Xh))
    bit1[Xh]+=x;
  return;
}
void Add2(int Xh,LL x)
{
  for(;Xh<=n;Xh+=lowbit(Xh))
    bit2[Xh]+=x;
  return;
}
LL Find1(int x)
{
  ret=0;
  for(;x;x-=lowbit(x))
    ret+=bit1[x];
  return ret;
}
LL Find2(int x)
{
  ret=0;
  for(;x;x-=lowbit(x))
    ret+=bit2[x];
  return ret;
}
bool cmp(Dee d,Dee e)
{
  return d.val<e.val;
}
int main()
{
freopen("thair.in","r",stdin);
freopen("thair.out","w",stdout);
  n=rei();
  for(int i=1;i<=n;i++)
    a[i].val=rel(),a[i].num=i;
  sort(a+1,a+1+n,cmp);
  int u;
  for(int i=1;i<=n;i++)
  {
    c[a[i].num]=i;
    u=i;
    while(a[i].val==a[i+1].val&&i<=n)
      i++,c[a[i].num]=u;
  }
  for(int i=1;i<=n;i++)
  {
    Add1(c[i],1);
  	Add2(c[i],Find1(c[i]-1));
  	ans+=Find2(c[i]-1);
  }
  wrl(ans);
  return 0; 
}
