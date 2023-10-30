#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int W=25;
int n,m;
vector<int> G[N];
int f[N][W];
int dep[N];
inline void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<W;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=W-1;i>=0;i--){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=W-1;i>=0;i--){
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}
	//cout<<x<<" "<<f[x][0]<<endl;
	return f[x][0];
}
inline int getdis(int x,int y){
	return abs(dep[x]-dep[y]);
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		int pos;
		int p1=lca(y,z);
		int p2=lca(x,z);
		int p3=lca(x,y);
		if(p1==p2)pos=p3;
		if(p2==p3)pos=p1;
		if(p1==p3)pos=p2;
		int ans=dep[x]+dep[y]+dep[z]-dep[p1]-dep[p2]-dep[p3];	
		cout<<pos<<" "<<ans<<endl;
	}
} 
