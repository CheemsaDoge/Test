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
int euler_phi(int n) {
	ri ans=n;
	for(ri i=2;i*i<=n;i++)
    if(n%i==0)
	{
    	ans/=i*(i-1);
    	while(n%i==0)n/=i;
    }
  if(n>1)	ans=ans/n*(n-1);
  return ans;
}
ll cifang(int a,int n)
{
	rl sum=1;
	while(n)
	{
		if(n&1)
			sum*=a;
		a*=a;
		n>>=1;
	}
	return sum;
}
int main()
{
//	freopen("2.3.in","r",stdin);
//	freopen("2.3.out","w",stdout);
	ri T,p;
	read(T);
	while(T--)
	{
		read(p);
		printf("%lld\n",cifang(4,euler_phi(p))%p);
	}
}
