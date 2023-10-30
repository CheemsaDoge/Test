#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n')
#define pn puts("Orz, I cannot find x!")
/*---------------------------------pre------------------------------------*/
int fast_pow(int a,int x,int p) {
	int no=a,ans=1;
	while(x){
		if(x&1) ans=int(1ll*ans*no%p);
		x>>=1;no=int(1ll*no*no%p);
	}
	return ans;
}
inline int BsGs(int a,int b,int p) //baby_step,giant_step
{
	/*initialize();*/b%=p;map<int,int>hash;hash.clear();hash[b]=0;int cfa=1;int t=int(sqrt(p))+1;
	for(int i=1;i<t;i++){cfa=int(1ll*cfa*a%p);hash[int(1ll*cfa*b%p)]=i;}a=int(1ll*cfa*a%p);
	if(a==0) return b==0?1:-1;
	for(int i=0;i<=t;i++){
		int val=fast_pow(a,i,p);
		int j=hash.find(val)!=hash.end()?hash[val]:-1;
		if(j>=0&&i*t-j>=0) return i*t-j;
	}
	return -1;
}
inline int exgcd(int a,int b,int&x,int&y) {
    if(!b) {
        x=1,y=0;
        return a;
    }
    int gcd=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return gcd;
}
int y,z,p;
int main() {
	int xx,yy;
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);	
	int T,k;read(T);read(k);while(T--){
		read(y);read(z);read(p);
		if(k==3)
		{
			int ans=BsGs(y,z,p);
			if(ans==-1) pn;
			else write(ans),pc;
		}
		else if(k==1){
			int ans=fast_pow(y,z,p);
			write(ans),pc;
		}
		else{
            int gcd=exgcd(y,p,xx,yy);
            if(z%gcd) pn;
            else {
                int temp=p/gcd;
                while(xx<0) xx+=temp;
                printf("%lld\n",((1ll*xx*z/gcd)%temp+temp)%temp);
            }
		}
	}
	return 0;
}
