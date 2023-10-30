#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+1146;
struct Matrix
{
	int h,l;
	int a[MAXN][MAXN];
};
Matrix operator*(Matrix x,Matrix y)
{
	Matrix res;
	res.h=x.h;
	res.l=y.l;
	for(int i=1;i<=x.h;i++)
		for(int j=1;j<=y.l;j++)
		{
			res.a[i][j]=0;
			for(int k=1;k<=x.l;k++)
				res.a[i][j]+=x.a[i][k]*y.a[k][j];
		}
} 

int main()
{
	
}
