/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int p=2;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int a[5],n,m,T;
int C(int n,int m){return m>n?0:1;}
int Lucas(int n,int m){
    if(!m) return 1;
    return C(n%p,m%p)*Lucas(n/p,m/p)%p;
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("stupid.in","r",stdin);
	freopen("stupid.out","w",stdout);
	read(T);a[0]=1;
    for(int i=1;i<=p;i++) a[i]=(a[i-1]*i)%p;
    while(T--){read(n),read(m);printf("%d\n",Lucas(n,m));}
    return 0;
}
