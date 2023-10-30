#include<bits/stdc++.h>
using namespace std;
const int MAXN = 306;
const int MAXM = 306 * 306;//n - m   300
struct Edge{
	int nxt,to;
}e[MAXN*2];
int cnt,head[MAXN],ans;
inline void AddEdge(int from,int to){
	e[++cnt].nxt = head[from];
	e[cnt].to = to;
	head[from] = cnt;
	return ;
}
int n,m,f[MAXN][MAXM][2],val[MAXN],w[MAXN],sumval,sumw,req;
bool BE_FA[MAXN];
void dfs(int u,int fa){
	if(BE_FA[u] == 0){
		f[u][w[u]][0] = f[u][w[u]][1] = val[u];
	}
	for(int i = head[u];i;i = e[i].nxt){
		const int v = e[i].to;
		if(v == fa)continue;
		dfs(v,u);
		f[u][min(i+w[u],req)][1] = min(f[u][min(i+w[u],req)][1],f[v][i][1]);
		
	}
	return ;
}
int main(){
	freopen("ballad.in","r",stdin);
	freopen("ballad.out","w",stdout);
	cin>>n>>m;
	for(int i = 2;i <= n;i++){
		int fa;
		cin>>fa;
		BE_FA[fa] = true;
		AddEdge(i,fa);
		AddEdge(fa,i);
	}
	for(int i = 1;i <= n;i++){
		cin>>w[i]>>val[i];
		sumw += w[i],sumval += val[i];
	}
	req = sumw - m;
	dfs(1,114514);
	for(int i = 0;i <= m;i++){
		ans = max(ans,f[1][i]);
	}
	cout<<ans;
	return 0;
}
/*
cout<<"point "<<u<<",("<<w[u]<<","<<val[u]<<"):";
for(int i = 0;i <= m;i++){
	if(f[u][i] != 0)cout<<"("<<i<<","<<f[u][i]<<") ";
}
cout<<endl;
*/
