#include<bits/stdc++.h>
using namespace std;
char a[2000010];
int n;
void NP(){
	puts("NOT POSSIBLE");
	exit(0);
}
void NU(){
	puts("NOT UNIQUE");
	exit(0);
}
int cnt;
int p=1;
int main(){
	freopen("friends.in","r",stdin);
	freopen("friends.out","w",stdout);
	scanf("%d",&n);
	if((n&1)==0){
		NP();
	}
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])continue;
		int flag=1;
		for(int j=(n>3000)?p:1;j<=n/2;j++){
//			printf("%d\n",j);
			if(a[j+(j>=i)]!=a[j+(n/2)+((j+(n/2))>=i)]){
				if(n>3000)i=max(i,j+((i>n/2)?n/2:0)-1);
//				printf("for %d, find %d %d not match\n",i,j+(j>=i),j+(n/2)+((j+(n/2))>=i));
				flag=0;
				break;
			}
			p=j;
		}
		if(flag){
			p=(i>n/2)?i-(n/1)-1:i-1;
//			printf("check:%d has done!\n",i);
			if(cnt)NU();
			else cnt=i;
		}
		if(i==1||i==n/2)p=1;
	}
	if(!cnt)NP();
	for(int i=1;i<=n/2;i++){
		printf("%c",a[i+(i>=cnt)]);
	}
	return 0;
} 
