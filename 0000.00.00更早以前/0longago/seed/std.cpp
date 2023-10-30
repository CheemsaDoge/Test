#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
#define maxn 1000000+1145
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
struct Map{
	struct Edge{
		int nxt,v,val;
	}edge[maxn*2];
	int head[maxn];
	int n,tot,maxpoint,maxsum,val[maxn],pre;
	bool vis[maxn];
	int length[2*maxn];
	void Initialize(int nn){
		n=nn;
		tot=0;
		while(nn--)
		{
			edge[n].nxt=0;
			edge[n].v=0;
		}
	}
	void add_edge(int u,int v)
	{
		edge[++tot].nxt=head[u];
		head[u]=tot;
		edge[tot].v=v;
	}
	#define nextpoint edge[i].v
	void bfs(int x)
	{
		for(int i=head[x];i!=0;i=edge[i].nxt)
			if(!vis[nextpoint])
			{
				vis[nextpoint]=1;
				val[nextpoint]=val[x]+1;
				if(maxsum<val[nextpoint]){
					maxsum=val[nextpoint];
					maxpoint=nextpoint;
				}
				bfs(nextpoint);
			}
	}
	int ask()
	{
		for(int i=1;i<=n;i++)
			bfs(i);
		return maxsum;
	}
}mapu;
int n,m;
int main(){
	freopen("data.in","r",stdin);
	freopen("std.out","w",stdout);
	int a,b;
	read(n);
	mapu.Initialize(n);
	for(int i=1;i<n;i++)
	{
		read(a);read(b);
		mapu.add_edge(a,b);
		mapu.add_edge(b,a);
	}
	printf("%d",mapu.ask());
}
