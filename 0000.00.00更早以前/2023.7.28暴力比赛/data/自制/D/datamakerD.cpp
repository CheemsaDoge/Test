#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
const int MAXval=500;
int main(){
	srand(time(0));
	freopen("D10.in","w",stdout);
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
		printf("%d %d %d\n",l,r,v);
	}
}
