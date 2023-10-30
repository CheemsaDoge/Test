#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rl register unsigned long long
#define ri register int
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const ll MAXN = 1e6+1145;

struct Matrix{
	int h,l;
	int a[120][120];
};
Matrix operator*(Matrix a,Matrix b)
{
	Matrix c;
	c.h=a.h;
	c.l=b.l;
	memset(c.a,0,120*120);
	for(int i=1;i<=a.h;i++)
		for(int n=1;n<=b.l;n++)
			c.a[i][n]+=a.a[i][n]*b.a[n][i];
	return c;
}
	Matrix a;
	Matrix b;
int main() 
{
	int n,m;
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			read(a.a[i][j]);
	a.h=n;a.l=m;
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			read(b.a[i][j]);
	b.h=n;b.l=m;
	a=a*b;
	for(int i=1;i<=a.h;i++)
	{
		for(int j=1;j<=a.l;j++)
			printf("%d ",a.a[i][j]);	
		cout<<endl;
	}
}

/*
2 2
1 2
3 4

2 4
1 2 3 4
1 2 3 4

ans:
6 12 18 24
7 14 21 28
*/
