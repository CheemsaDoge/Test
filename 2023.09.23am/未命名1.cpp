#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 5;
//#define int long long
inline int read()
{
	int x = 0, w = 0;
	char ch = 0;
	
	while (!isdigit(ch))
	{
		w |= ch == '-';
		ch = getchar();
	}
	while (isdigit(ch))
	{
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}	
	return w ? -x : x;
}
struct node {
	int to,ord;
	node(int to_)
	{
		to = to_;
	}
	node() {
	}
};
vector< vector<node> > a;
inline void add(int u, int v)
{
	a[u].push_back(node(v));
}
int n,m,s,p;
int dfn[MAX],low[MAX],dep,ans;
bool vis[2*MAX];
void tarjan(int u,int fa)
{
	dep++;
	dfn[u]=low[u]=dep;
	for(int i=0;i<a[u].size();i++)
	{
		int v=a[u][i].to;
		if(v==fa)
		{
			continue;
		}
//		cout<<"v:"<<v<<endl;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v])
			{
				ans++;
			}
		}
		else
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
	return;
}
void init()
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	dep=0;
	ans=0;
}
signed main()
{
	cin>>n>>m;
	while(n)
	{
		a.clear();
		a.resize(n+1);
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		init();
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]&&!a[i].empty())
				tarjan(i,i);
		}
		cout<<ans<<endl;
		cin>>n>>m;
	}
	return 0;
}
