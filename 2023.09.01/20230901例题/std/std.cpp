#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fuck printf("fuck\n");

template <typename T> inline void read (T &x)
{
	x=0;
	int f=1;
	char c=getchar();
	for(; !isdigit(c); c=getchar()) if(c=='-') f=-1;
	for(; isdigit(c); c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if(f<0) x=-x;
}
template <typename T> inline void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}


const ll maxn=2111;
int n,m,ans;
char a[maxn][maxn];
int up[maxn][maxn],zuo[maxn][maxn],you[maxn][maxn];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n);
	read(m);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
//    		scanf("\n%c",&a[i][j]);
			cin>>a[i][j];
			if(a[i][j]=='F')
			{
				up[i][j]=1;
				zuo[i][j]=j;
				you[i][j]=j;
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=2; j<=m; j++)
		{
			if(a[i][j-1]=='F'&&a[i][j]=='F')
			{
				zuo[i][j]=zuo[i][j-1];
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=m; j>=2; j--)
		{
			if(a[i][j-1]=='F'&&a[i][j]=='F')
			{
				you[i][j-1]=you[i][j];
			}
		}
	}
//	cout<<you[7][12]<<endl;
//	cout<<you[8][12]<<endl;
//	cout<<you[9][12]<<endl;
//	cout<<you[10][12]<<endl;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(a[i][j]==a[i-1][j]&&i>1&&a[i][j]=='F')
			{
				up[i][j]=up[i-1][j]+1;
				zuo[i][j]=max(zuo[i][j],zuo[i-1][j]);
				you[i][j]=min(you[i][j],you[i-1][j]);
			}
			ans=max(ans,up[i][j]*(you[i][j]-zuo[i][j]+1));
		}
	}
//	cout<<you[7][12]<<endl;
//	cout<<you[8][12]<<endl;
//	cout<<you[9][12]<<endl;
//	cout<<you[10][12]<<endl;
	cout<<ans*3<<endl;
	return 0;
}
/*
20 20
F F F F F R R R R R R R R R R R R R R R 
F F F F F R R R R R R R R R R R R R R R 
F F F F F R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R F F R R R R R 
R R R R R R R R R R R R R F F R R R R R 
R R R R R R R R R R R F F F F R R R R R 
R R R R R R R R R R F F F F F R R R R R 
R R R R R R R R R F F F F F F R R R R R 
R R R R R R R R R F F F F F F R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 
R R R R R R R R R R R R R R R R R R R R 


*/

