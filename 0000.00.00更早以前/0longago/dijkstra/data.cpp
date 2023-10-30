#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("dijkstra_data.in","w",stdout);
	srand(time(0));
	int n=rand()%100000;
	int m=rand()%100000;
	int s=rand()%n;
	int e=rand()%n;
	printf("%d %d %d %d\n",n,m,s,e);
	m--;
	printf("%d %d %d \n",s,e,1145);
	while(m--)	
	{
		int x,y,z;
		x=rand()%n;
		y=rand()%n;
		z=rand()%11451;
		printf("%d %d %d \n",x,y,z);
	}
}
