#include<bits/stdc++.h>
using namespace std;
int vis[1011145];
int main()
{
	freopen("data.in","w",stdout);
	srand(time(0));
	int n=rand()%100000+2;
	printf("%d\n",n);
	int x,y=n;
	while(y--)	
	{
		x=(rand()%(n-1))+1;
		printf("%d %d\n",y+1,y);
		if(y==1)	return 1;
	}
}
