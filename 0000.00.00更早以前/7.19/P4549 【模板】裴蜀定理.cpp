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
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
ll inv[int(3e6+1145)];
int main()
{
	int n;
	read(n);
	ri x,y;
	read(x);
	if(x<=0)
		x=-x;
	for(int i=1;i<n;i++)
	{
		read(y);
		if(y<0)
			y=-y;
		x=gcd(x,y);
	}
	printf("%d",x);
}


