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
int main()
{
	bool s=1;
	int n,m,T;
	read(T);
	while(T--)
	{
		s=true;
		read(n);read(m);
		if(m>n+1)
		{
			printf("Yes\n");
			s=false;
		}
		else
			for(int i=1;i<=m;i++)
				if(n%i!=i-1)
				{
					s=false;
					printf("Yes\n");
					break;
				}
		if(s)
			printf("No\n");
	}
	
}


