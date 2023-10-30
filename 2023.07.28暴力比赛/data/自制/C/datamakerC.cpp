#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e1;
const int MAXval=500;
int main(){
	srand(time(0));
	freopen("C1.in","w",stdout);
	int n=MAXN;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) printf("%d ",rand()%MAXval+1);
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		int l,r,v;
		r=rand()%n+1;
		l=rand()%r+1;
		v=rand()%MAXval;
		int opt=rand()%2;
		printf("%d %d %d %d\n",opt,l,r,v);
	}
}
