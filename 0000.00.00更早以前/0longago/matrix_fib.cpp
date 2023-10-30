#include<bits/stdc++.h>
using namespace std;
#define MAXN 10

struct Matrix{
	int a[MAXN][MAXN];
	int n,m;
	void pr(){
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
};

Matrix operator*(Matrix x,Matrix y)///
{
	Matrix ret;
	for(int i=1;i<=x.n;i++)
	{
		for(int j=1;j<=y.m;j++)
		{
			ret.a[i][j]=0;
			for(int k=1;k<=x.m;k++)
				ret.a[i][j]+=x.a[i][k]*y.a[k][j];
		}
	}
	ret.n=x.n;
	ret.m=y.m;
	return ret;
}
Matrix qmul(Matrix x,int b)
{
	Matrix ret;
	ret.n=x.n;
	ret.m=x.m;
	for(int i=1;i<=x.n;i++)
	
	for(int i=1;i<=x.n;i++)
		ret.a[i][i]=1;
	while(b>0)
	{
		if(b&1)
		{
			ret=ret*x;
		}
		x=x*x;
		b>>=1;
	}
	return ret;
}
int main(){
	int n;
	cin>>n;
	Matrix A,B;
	A.n=2;
	A.m=1;
	A.a[1][1]=1;
	A.a[2][1]=1;
	B.n=2;
	B.m=2;
	B.a[1][1]=1;B.a[1][2]=1;
	B.a[2][1]=1;B.a[2][2]=0;
	Matrix f=A*qmul(B,n-1);
	printf("%d",f.a[1][1]);
	return 0;
}

//0 1 2 3 4 5
//1 2 3 5 8 13 


