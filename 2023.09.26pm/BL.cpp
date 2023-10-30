#include<bits/stdc++.h>
using namespace std;
int f_max[100010][20];
int f_min[100010][20];
int a[100010];
int N,K;
void solve(){
	int t=log(N)/log(2)+1;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=t;j++){
			f_max[i][j]=INT_MIN;
			f_min[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=N;i++){
		f_max[i][0]=a[i];
		f_min[i][0]=a[i];
	}
	for(int j=1;j<t;j++){
		for(int i=1;i<=N-(1<<j)+1;i++){
			f_max[i][j]=max(f_max[i][j-1],f_max[i+(1<<(j-1))][j-1]);
			f_min[i][j]=min(f_min[i][j-1],f_min[i+(1<<(j-1))][j-1]);
		}
	}
}
int main()
{
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	solve();
	for(int i=1;i<=K;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		int t=log(r-l+1)/log(2);
		printf("%d\n",max(f_max[l][t],f_max[r-(1<<t)+1][t])-min(f_min[l][t],f_min[r-(1<<t)+1][t]));
	}
}
