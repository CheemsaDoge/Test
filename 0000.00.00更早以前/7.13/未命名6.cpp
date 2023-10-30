#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e8+9999999;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ll long long int
#define rl register long long int
#define ri register int
struct Matrix
{
	int h,l;
	int a[4][4];
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
		freopen("1.1.out","w",stdout);
		bool a=1;
		int q=0;
	for(int i=1;i<=1000;i++)
	{
		if(1000%i)
		{
			q+=1000%i;
			printf("%d %d\n",i,1000%i);
			a=0;
		}
		else
		{
			if(!a)
				cout<<"ss"<<q<<endl<<endl;
			a=1;
			q=0;
		}
	}
		
}
