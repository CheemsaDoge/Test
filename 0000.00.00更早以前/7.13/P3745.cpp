#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=3e5+1145;
#define ri register int
#define rl register long long 
#define ll long long 
ll A,B,C;
int INF=2147483646;
int n,m;
int t[MAXN];
priority_queue<int>b;
int last=-INF;
int main()
{
	read(A);
	read(B);
	read(C);
	read(n);
	read(m);
	ri x;
	for(ri i=1;i<=n;i++)	read(t[i]);
	for(ri j=1;j<=m;j++)	read(x),b.push(x);
	
}

//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//4

//2

