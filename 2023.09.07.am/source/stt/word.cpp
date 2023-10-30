#include<bits/stdc++.h>
using namespace std;
int n;
int nt;
int num;
struct node{
	int s[27];
	int cnt;
}T[600005];
int a[500005];
char in[500005];
long long ans;
int cur;
int dfn[100005];
void build(int x){
	int p=0;
	for(int i=1;i<=num;i++){
		p=(!T[p].s[a[i]])?T[p].s[a[i]]=++nt:T[p].s[a[i]];
		if(i==num)T[p].cnt=x;
	}
}
vector<int>son[100005];
int fa[100005],size[100005];
void dfs_bac(int now=0,int fath=0){
	if(T[now].cnt){
		son[fath].push_back(T[now].cnt);
		fa[T[now].cnt]=fath;
	}
	for(int i=0;i<26;i++){
		if(T[now].s[i])dfs_bac(T[now].s[i],(T[now].cnt)?T[now].cnt:fath);
	}
}
void dfs_conson(int now=0){
	int top=son[now].size();
	for(int i=0;i<top;i++){
		dfs_conson(son[now][i]);
		size[now]+=size[son[now][i]];
	}
	size[now]++;
}
void dfs_ans(int now=0){
	dfn[now]=cur++;
	ans+=dfn[now]-dfn[fa[now]];
	int top=son[now].size();
	for(int i=0;i<top;i++){
		dfs_ans(son[now][i]);
	}
}
bool cmp(int xa,int xb){
	return size[xa]<size[xb];
}
//void show(){
//	puts("");
//	for(int i=1;i<=n;i++){
//		printf("%d fa=%d size=%d dfn=%d\n",i,fa[i],size[i],dfn[i]);
//	}
//}
int main(){
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",in);
		num=strlen(in);
		for(int j=0;j<num;j++){
			a[num-j]=in[j]-'a';
		}
		build(i);
	}
	dfs_bac();
	dfs_conson();
	for(int i=1;i<=n;i++){
		sort(son[i].begin(),son[i].end(),cmp);
	}
	dfs_ans();
	printf("%lld",ans);
//	show();
	return 0;
}
