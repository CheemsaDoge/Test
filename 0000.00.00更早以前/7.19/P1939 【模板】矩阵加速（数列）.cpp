#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ll long long
#define ri register int
#define rl register long long
#define ul unsigned long long
const int N=5;
struct Matrix{
	int h,l;
	int a[N][N];
};
Matrix operator *(Matrix a,Matrix b)
{
	Matrix c;
	c.h=a.h;
	c.l=b.l;
	for(int i=1;i<=a.l;i++)
	{
		for(int j=1;j<=b.l;j++)
		{
			for(int q=1;1<=a.h)
		}
	}
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	
	
}


