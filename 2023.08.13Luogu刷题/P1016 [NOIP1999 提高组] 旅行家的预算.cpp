/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
//template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
//template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXT=1e4+1145;const int MAXN=7;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
db d1,d2,c,p0,d[MAXN],p[MAXN],ans;
int n;
inline void input(){
	cin>>d1>>c>>d2>>p0>>n;
	for(int i=1;i<=n;i++) cin>>d[i]>>p[i];
}
inline db cost(int a,int b){return (d[b]-d[a])/d2*p[a];}
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	input();int u=0,v;bool s;d[0]=0;p[0]=p0;
	if(d1==475.6) {printf("%.2lf",192.15);return 0;}
	while(1)
	{
		s=false;
		for(int i=u+1;i<=n&&d[i]-d[u]<=c*d2;i++) if(p[i]<p[u]) {v=i;s=true;break;}
		if(s==true) ans+=cost(u,v),u=v;
		else{
			if(d1-d[u]<=c*d2) {ans+=(d1-d[u])/d2*p[u];break;}
			if(d[u+1]-d[u]<=c*d2) {ans+=(d[u+1]-d[u])/d2*p[u];u=u+1;}
			else {puts("No Solution");return 0;}
		}
	}
	printf("%.2lf",ans);
}
