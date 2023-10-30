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
const int MAXN=1e6+1145;
int a[MAXN];
int n;
inline void add(int pos,int val)
{
	for(int i=pos;i<=n;i+=i & -i)
		a[i]+=val;
}
inline int query(int x)
{
	ri sum=0;
	for(int i=x;i>=1;i-=(i& -i))
		sum+=a[i];
	return sum;
}
int  value[MAXN];
int main(){
	ri x,y,k,m;
	read(n);read(m);
	for(ri i=1;i<=n;i++)	read(value[i]);
	for(ri i=1;i<=n;i++)	add(i,value[i]-value[i-1]);
	while(m--)
	{
		read(x);
		if(x-1)	read(x),printf("%d\n",query(x));
		else	read(x),read(y),read(k),add(x,k),add(y+1,-k);
	}
}
