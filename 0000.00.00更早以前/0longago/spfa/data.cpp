#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("spfa_data.in","w",stdout);
	srand(time(0));
	int n=rand()%100000;
	int m=rand()%100000;
	printf("%d %d\n",n,m);
	m--;
	printf("%d %d %d \n",1,n,1145);
	while(m--)	
	{
		int x,y,z;
		x=rand()%n;
		y=rand()%n;
		z=rand()%11451;
		printf("%d %d %d \n",x,y,z);
	}
}
