#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=1e5+1145;
struct Edge{
	int u,to,val;
}edge[MAXN*4];
int totr=0;
inline void add_edge(int u,int v,int val)
{
	edge[++totr].to=v;
	edge[totr].u=u;
	edge[totr].val=val;
}
int fa[MAXN];
inline void initialize(int n)
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int find(int x)
{
   return fa[x]==x?x:find(fa[x]);
}
bool cmp(Edge a,Edge b)
{
    return a.val<b.val;
}
int cnt,ans;
int main()
{
	int m,n,a,b,c;
    read(n);
	read(m);
    initialize(n);
    for(int i=1;i<=m;i++)
    {
        read(a);
        read(b);
        read(c);
        add_edge(a,b,c);
    }
   ans=0;
   int ev,eu;
   sort(edge+1,edge+1+totr,cmp);
   for(int i=1;i<=totr;i++)         //O(m)
   {
        eu=find(edge[i].u), ev=find(edge[i].to);
        if(eu==ev)
            continue;
        ans+=edge[i].val;
        fa[ev]=eu;
        if(++cnt==n-1)
            break;
   }
   if(cnt<n-1)
   	printf("-1\n");
	else
   printf("%lld\n",ans);
}
