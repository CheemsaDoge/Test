#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ri register int
#define rl register long long 
int main()
{
	rl a,n,p;
	rl sum=1;
	read(a);
	read(n);
	read(p);
	rl nn=n;
	rl aa=a;
	while(nn)
	{
		if(nn&1)
		{
			sum*=aa;
			sum%=p;
		}
		aa*=aa;
		aa%=p;
		nn>>=1;
	}
	printf("%lld^%lld mod %lld=%lld",a,n,p,sum);
}

