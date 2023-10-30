#include<bits/stdc++.h>
using namespace std;
int n,m,num;
int nt;
struct node{
	int s[2];
	int end_cnt,pass_cnt;
}T[800005];
int a[10005];
void build(){
	int p=0;
	for(int i=1;i<=num;i++){
		p=(!T[p].s[a[i]])?T[p].s[a[i]]=++nt:T[p].s[a[i]];
		if(i<num)T[p].pass_cnt++;
		else T[p].end_cnt++;
	}
}
int query(){
	int ret=0,p=0;
	for(int i=1;i<=num;i++){
		p=T[p].s[a[i]];
		ret+=T[p].end_cnt;
		if(!p)break;
	}
	return ret+T[p].pass_cnt;
}
//void show(){
//	for(int i=0;i<=nt;i++){
//		printf("%d 0>%d 1>%d pass=%d end=%d\n",i,T[i].s[0],T[i].s[1],T[i].pass_cnt,T[i].end_cnt);
//	}
//}
int main(){
	freopen("sec.in","r",stdin);
	freopen("sec.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		for(int j=1;j<=num;j++){
			scanf("%d",&a[j]);
		}
		build();
	}
//	show();
	for(int i=1;i<=m;i++){
		scanf("%d",&num);
		for(int j=1;j<=num;j++){
			scanf("%d",&a[j]);
		}
		printf("%d\n",query());
	}
	return 0;
}
