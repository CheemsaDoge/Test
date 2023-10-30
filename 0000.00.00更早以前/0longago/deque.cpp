#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
#define maxn 1000000+1145
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
int w[maxn];
int res[maxn],deq[maxn];
int n,k;

int main()
{
	freopen("deque.in","r",stdin);
	read(n); read(k);
	for(int i=1;i<=n;i++)
		read(w[i]);
	int l=1,r=1;
	deq[1]=1;
	for(int i=2;i<=n;i++)
	{
		while(l<r&&w[i]<w[deq[r]])	r--;
		deq[++r]=i;
		if(i-k>=0)
			res[i-k]=w[deq[l]];
		if(deq[l]==i-k+1) l++;
	}
	for(int i=0;i<=n-k;i++)
		printf("%d\n",res[i]);
}
