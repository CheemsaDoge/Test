/*‘≠…Ò∆Ù∂Ø£°*/
#include <bits/stdc++.h>
using namespace std;

template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=1e6+1145;
#define ll long long
#define ri register int
#define rl register long long
#define ul unsigned long long
struct EDGE{
	int u,v,nxt;
}edge[MAXN];
int rd[200];
int head[200],totr;
void add_edge(int u,int v)
{
	edge[++totr].nxt=head[u];
	head[u]=totr;
	edge[totr].u=u;
	edge[totr].v=v;
	rd[v]++;
}
int n;
bool vis[200];
#define v (edge[i].v)
void topo()
{
	queue<int>a;
	for(int i=1;i<=n;i++)
		if(!rd[i])
			a.push(i);
	while(!a.empty())
	{
		int u=a.front();
		printf("%d ",u);
		a.pop();
		for(int i=head[u];i;i=edge[i].nxt)
		{
			rd[v]--;
			if(!rd[v])a.push(v);
			
		}
	}
}
int main()
{
	int x;
	read(n);
	for(int i=1;i<=n;i++)
	{
		while(1)
		{
			read(x);
			if(x==0) break;
			add_edge(i,x);
		}
	}
	topo();
}
