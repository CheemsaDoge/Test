#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define ri register int
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
int n,m;
int a[1000000];
int main(){
	ri op;
	freopen("BIT.in","r",stdin);
	freopen("std.out","w",stdout);
	read(n);
	for(ri i=1;i<=n;i++)
		read(a[i]);
	read(m);
	int sum;
	int l,r,x;
	while(m--)
	{
		read(op);
		if(op==1)
		{		
			read(l);
			read(x);
			a[l]+=x;
		}
		else
		{
			sum=0;
			read(l);
			for(int i=1;i<=l;i++)
				sum+=a[i];
			printf("%d\n",sum);
		}
	}
}
