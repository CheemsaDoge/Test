#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define rl register long long 
#define ll long long
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
int main()
{
//	freopen("comb2.in","r",stdin);
//	freopen("comb2.out","w",stdout);
	rl k,x;
	read(x);
	read(k);
	printf("%d %d\n",x-k+1,1);
	for(int i=2;i<=k;i++)
		printf("%d %d\n",i,i);
}

