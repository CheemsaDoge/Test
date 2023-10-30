#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("segtree.in","w",stdout);
	srand(time(0));
	int n=rand()%9000090+100;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%1000);
	int m=rand()%100;
	cout<<endl<<m<<endl;
	while(m--)
	{
		int op=rand()%2+1;
		cout<<op<<" ";
		if(op==1)
		{
			int r=rand()%(n-10)+9;
			int l=rand()%r+1;
			int x=rand()%10;
			printf("%d %d %d \n",l,r,x);
		}
		else
		{
			int r=rand()%(n-10)+9;
			int l=rand()%r+1;
			printf("%d %d \n",l,r);
		}
	}
}
