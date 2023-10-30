#include<iostream>
#include<cstdio>
using namespace std;
int n,a[501][501]; 
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	   for(int j=i+1;j<=n;j++)
	       	scanf("%d",&a[i][j]),a[j][i]=a[i][j];
	int ans=0;
for(int i=1;i<=n;i++)
	{int ma=0;
		for(int j=1;j<=n;j++)
	   {
	   	ma=max(ma,a[i][j]);
	   }
	   	for(int j=1;j<=n;j++)
	   {
	   	if(a[i][j]!=ma)
	   	ans=max(ans,a[i][j]);
	   }
	}
	cout<<1<<endl<<ans;
	return 0;
}
