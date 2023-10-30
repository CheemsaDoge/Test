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
bool a[665536];
bool b[665536];
int main()
{
	memset(b,0,665536);
	int sum=0;
	int l,r;
	read(l);
	read(r);
	for(int i=2;i<=sqrt(r);i++)
		if(!a[i])
			for(int j=2;j*i<=sqrt(r);j++)
				a[j*i]=1;
	for(int i=2;i<=sqrt(r);i++)
	{
		if(!a[i])
			for(int j=max(2,j/i);j*i<=r;j++)
				b[j*i-l]=1;
	}
	for(int i=0;i<=r-l;i++)
		if(!b[i])
			sum++;
	printf("%d",sum);
}
