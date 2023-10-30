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
const int N=1e6+1145;
const int MAXN=3e4+1145;
#define w (*this)
void print(char* a)
{
	for(int i=strlen(a);i>=1;i--)
		printf("%d",int(a[i]));
}
char a[5000];
int main()
{	
	a[1]=1;
	int b;
	printf("%d",strlen(a));
	read(b);
	for(int i=1;i<=b;i++)
	{
		int n=strlen(a);
		for(int i=1;i<=n+1;i++)
			a[i]*=b;
		for(int i=1;i<=n;i++)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
			if(i==n&&a[i+1]!=0)
				n++;
		}
	}
	a[1]+=1;
	for(int i=1;;i++)
	{
		if(a[i]<10)
			break;
		a[1+i]+=a[i]/10;
		a[i]%=10;
	}
	print(a);
}
