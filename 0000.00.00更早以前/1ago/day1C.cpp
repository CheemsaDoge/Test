#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+1145;
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
inline int gcd(int a,int b)
{
	if(a<b)	swap(a,b);
	if(!b)	return a;
	return gcd(b,a%b);
}
inline ll find(int x,int y)
{
	rl res=0;
	for(int i=x;i<=sqrt(y*x);i+=x)
		if(!(y%i))
			if(x==gcd(i,x*y/i))
				res++;
	int q=y*x;
	if((!(y%(int(sqrt(q)))))&&(sqrt(q)*sqrt(q)==q)&&(gcd(sqrt(q),sqrt(q))==x))
		return res*2-1;
	return res*2;
}
int main()
{
	rl x,y;
	read(x);
	read(y);
	printf("%lld",find(x,y));
}
/*
if(x0==1)
	O(y0)
else
	O(x0*y0/x0)=O(y0)
*/
/*
O(sqrt(y0)*2)=O(sqrt(y0))
*/
