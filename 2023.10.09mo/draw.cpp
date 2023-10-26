#include<cstdio>
#include<cstring>
#include<algorithm>
#define f_inline inline __attribute__((always_inline))
using namespace std;
int a,b,c,n,m;
char ans[400][400];
f_inline void Print()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			putchar(ans[i][j]);
		putchar('\n');
	}
}
int main() 
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		n=2*c+2*b+1;
		m=2*a+2*b+1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				ans[i][j]='.';
		for(int i=1;i<=1+2*b;i+=2)
			for(int j(m-(2*a+1+i)+2),k=1;k<=2*a+1;++j,++k)
				if(k&1) ans[i][j]='+';
				else ans[i][j]='-';
		for(int i(n-2*c);i<=n;i+=2)
		{
			ans[i][1]='+';
			for(int j=1;j<=a;++j)
			{
				ans[i][j*2]='-';
				ans[i][j*2+1]='+';
			}
		}
		for(int i=1,k(m);i<=1+2*b;i+=2,k-=2)
			for(int j(i),kk=1;kk<=2*c+1;++j,++kk)
				if(kk&1) ans[j][k]='+';
				else ans[j][k]='|';
		for(int i(n-2*c+1);i<n;++i)
		{
			ans[i][1]='|';
			for(int j=1;j<=a;++j)
				ans[i][j*2+1]='|';
		}
		for(int i(2),k=1;k<=b;i+=2,++k)
			for(int j(m-2*a-i+1),kk=1;kk<=a+1;++kk,j+=2)
				ans[i][j]='/';

		for(int i=1,k=1;k<=c+1;++i,++k)
		{
			int x(2*i),y(m-1);
			for(int j=1;j<=b;++j,x+=2,y-=2)
			{
				ans[x][y]='/' ;
			}
		}
		Print();
	}
	return 0;
}
