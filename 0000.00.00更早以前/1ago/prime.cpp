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

bool a[100000000];
int mm[100000000];
int totr;
int main()
{
	freopen("prime.in","w",stdout);
	int sum=0;
	for(int i=2;i<=sqrt(int(1e9));i++)
	{
		if(!a[i])
			for(int j=2;j*i<=sqrt(int(1e9));j++)
				a[j*i]=1;
		if((!a[i]))
			printf("%d,",i);
	}
}
