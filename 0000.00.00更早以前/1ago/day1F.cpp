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
bool heshu[MAXN];
int prime[MAXN/10];
int m[MAXN];
inline int shai(int n)
{
	ri totr=0;
	for(ri i=2;i<=n;i++)
	{
		if(!(heshu[i]))
		{
			m[i]=i;
			prime[++totr]=i;
		}
		for(ri j=1;j<=totr&&prime[j]*i<=n;j++)
		{
			if(prime[j]>m[i])	break;
			heshu[prime[j]*i]=1;
			m[prime[j]*i]=prime[j];
		}
	}
	return totr;
}
int main()
{
	ri n;
	read(n);
	ri sum=shai(n);
	printf("%d ",sum);
	ri m;
	ri x;
}
