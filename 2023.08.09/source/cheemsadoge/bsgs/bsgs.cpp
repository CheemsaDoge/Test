/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXsP=40655;const int INF=2147483647ll;//2^31-1
#define db double
int fast_pow(int a,int x,int p) //fast_pow
{
	int no=a,ans=1;
	while(x){
		if(x&1) ans=1ll*ans*no%p;
		x>>=1;no=1ll*no*no%p;
	}
	return ans;
}
inline int BsGs(int a,int b,int p) //baby_step,giant_step
{
	/*initialize();*/b%=p;int ans=INF;map<int,int>hash;hash.clear();hash[b]=0;int cfa=1;int t=int(sqrt(p))+1;
	for(int i=1;i<t;i++){cfa=1ll*cfa*a%p;hash[1ll*cfa*b%p]=i;}a=1ll*cfa*a%p;
	if(a==0) return b==0?1:-1;
	for(int i=0;i<=t;i++){
		int val=fast_pow(a,i,p);
		int j=hash.find(val)!=hash.end()?hash[val]:-1;
		if(j>=0&&i*t-j>=0) return i*t-j;
	}
	return -1;
}
int a,b,p;
int main() {
//	freopen("bsgs.in","r",stdin);
//	freopen("bsgs.out","w",stdout);	
//	int T;read(T);while(T--){
		read(p);read(a);read(b);
		int ans=BsGs(a,b,p);
		if(ans==-1) printf("no solution\n");
		else printf("%d\n",ans);
//	}
	return 0;
}
