#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
inline int read()
{
    int ans = 0,op = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') op = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        (ans *= 10) += ch - '0';
        ch = getchar();
    }
    return ans * op;
}
const int maxn = 2005;
struct egde
{
	int to,next,cost;
}e[maxn * 10];
int fir[maxn],alloc;
inline void adde(int u,int v,int w)
{
	e[++alloc].next = fir[u];
	fir[u] = alloc;
	e[alloc].to = v;
	e[alloc].cost = w;
}
int n,m;
int dis[maxn],popst[maxn],minm;
bool instack[maxn];
void spfa(int s)
{
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	q.push(s);
	instack[s] = 1;
	while(q.size())
	{
		int u = q.front();
		q.pop();
		popst[u]++;
		if(popst[u] > n - 1) { printf("NO SOLUTION"); return;}
		instack[u] = 0;
		for(int i = fir[u];i;i = e[i].next)
		{
			int v = e[i].to,w = e[i].cost;
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if(!instack[v]) q.push(v),instack[v] = 1;
			}
		}
	}
	for(int i = 1;i <= n;i++) minm = min(minm,dis[i]);
	for(int i = 1;i <= n;i++) printf("%d\n",dis[i] - minm);
}
int main()
{
	n = read(),m = read();
	for(int i = 1;i <= m;i++)
	{
		int u = read(),v = read(),w = read();
		adde(v,u,w);	
	}
	for(int i = 1;i <= n;i++) adde(n + 1,i,0);
	spfa(n + 1);
}
