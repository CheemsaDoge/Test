#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100010
int n,k,zj,num,ans_k;
int cut,head[N],ver[2*N],nxt[2*N];
int deep[N],f[N],maxdeep[N],ans[N];
bool cmp(int a,int b){
	return a>b;
}
void add(int x,int y){
	ver[++cut]=y;nxt[cut]=head[x];head[x]=cut;
}
//ÇóÖ±¾¶
void dfs1(int x,int fa){
	if(deep[x]>zj){
		zj=deep[x];
		num=x;
	}
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)continue;
		deep[y]=deep[x]+1;
		dfs1(y,x);
	}
}
void dfs2(int x,int fa){
	if(deep[x]>zj){
		zj=deep[x];
		num=x;
	}
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)continue;
		deep[y]=deep[x]+1;
		f[y]=x;
		dfs2(y,x);
	}
}
//
void dfs_k(int x,int fa){
	maxdeep[x]=deep[x];
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa)continue;
		deep[y]=deep[x]+1;
		dfs_k(y,x);
		maxdeep[x]=max(maxdeep[x],maxdeep[y]);
	}
}
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i){
    	int x,y;
    	scanf("%d%d",&x,&y);
    	add(x,y);
    	add(y,x);
	}
	dfs1(1,0);
	memset(deep,0,sizeof(deep));
	zj=0;
	dfs2(num,0);
	int kkk=num;
	for(int i=1;i<=(deep[num]+1)/2;++i)kkk=f[kkk];
	memset(deep,0,sizeof(deep));
	dfs_k(kkk,0);
	for(int i=1;i<=n;++i)ans[i]=maxdeep[i]-deep[i];
	sort(ans+1,ans+n+1,cmp);
	for(int i=k+1;i<=n;++i)ans_k=max(ans_k,ans[i]+1);
	printf("%d\n",ans_k);
    return 0;
}
