#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct candy{
	int X,A,B;
}q[101010];
int n,k;
int a[101010];
int main()
{
	//freopen("a.in","r",stdin);
	cin>>n>>k;
	for (int i=1; i<=k; i++){
		scanf("%d%d%d",&q[i].X,&q[i].A,&q[i].B);
	}
	for (int i=1; i<=n; i++) a[i]=1;
	for (int T=1; T<=200; T++){
		for (int i=1; i<=k; i++){
			if (q[i].X==1) {
				if (a[q[i].A]>a[q[i].B]) a[q[i].B]=a[q[i].A];
				else a[q[i].A]=a[q[i].B];
			}
			else if (q[i].X==2){
				if (a[q[i].A]>=a[q[i].B]) a[q[i].B]=a[q[i].A]+1;
			}
			else if (q[i].X==3){
				if (a[q[i].A]<a[q[i].B]) a[q[i].A]=a[q[i].B];
			}
			else if (q[i].X==4){
				if (a[q[i].A]<=a[q[i].B]) a[q[i].A]=a[q[i].B]+1;
			}
			else if (q[i].X==5){
				if (a[q[i].A]>a[q[i].B]) a[q[i].B]=a[q[i].A];
			}
		}
	}
	for (int i=1; i<=k; i++){
		if (q[i].X==1) {
				if (a[q[i].A]>a[q[i].B]) {cout<<"-1";return 0;}
			}
			else if (q[i].X==2){
				if (a[q[i].A]>=a[q[i].B]) {cout<<"-1";return 0;}
			}
			else if (q[i].X==3){
				if (a[q[i].A]<a[q[i].B]) {cout<<"-1";return 0;}
			}
			else if (q[i].X==4){
				if (a[q[i].A]<=a[q[i].B]) {cout<<"-1";return 0;}
			}
			else if (q[i].X==5){
				if (a[q[i].A]>a[q[i].B]) {cout<<"-1";return 0;}
			}
	}
	long long ans=0;
	for (int i=1; i<=n; i++) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}
