/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=20;const int MAXM=4;const int MAXT=35;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int T;
int n,m;
struct Point{
	db x,y,x2;
	db ask_y(db a,db b) {return a*x2+b*x;}
	bool dead(db a,db b) {return ask_y(a,b)==y?true:false;}
}a[MAXN];
int main() {
	freopen("angrybirds.in","r",stdin);
	freopen("angrybirds.out","w",stdout);	
	read(T);
	while(T--)
	{
		read(n);read(m);
		for(int i=1;i<=n;i++) scanf("%f%f",&a[i].x,&a[i].y),a[i].x2=a[i].x*a[i].x;
	}
	return 0;
}
