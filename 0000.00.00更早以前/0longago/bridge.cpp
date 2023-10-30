#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int s = 0,w = 1;
    char g = getchar();
    while(g<'0'||g>'9'){if(g=='-')w*=-1;g = getchar();}
    while(g>='0'&&g<='9'){s = s*10+g-'0';g = getchar();}
    return s*w;
}
#define MAXV 114514
//±í°×çæ¶äÀò 
vector<int> G[MAXV];  //Í¼ 
int V,m;
int color[MAXV];  //¶¥µãµÄÑÕÉ«
bool dfs(int v,int c){
    color[v] = c;
    for(int i = 0;i < G[v].size(); i++)
	{
        if(color[G[v][i]] == c) return false;
        if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
    }
    return true;
}

void solve()
{
    for(int i = 0;i < V; i++)
        if(color[i] == 0)
            if(!dfs(i,1))
			{
                printf("N0\n");
                return;
            }
    printf("YE5\n");
}
int main()
{
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
	V=read();
	m=read();
	int a,b;
	for(int i=1;i<=m;i++)
	{
		a=read();
		b=read();
		G[a].push_back(b);
		G[b].push_back(a);
	}
	solve();	
}
