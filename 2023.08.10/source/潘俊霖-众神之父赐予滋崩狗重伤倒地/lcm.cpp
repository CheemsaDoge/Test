/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXM=23;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
ll a,b;
ll t;
int ask_gcd(int a,int b)
{
	if(a<b) return ask_gcd(b,a);
	return b==0?a:ask_gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a*b/ask_gcd(a,b);
}
long long n;
int main() {
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	read(a);read(b);
	if(a>b) swap(a,b);
	ll gcd=b-a;
	int i; 
	if(b%a==0||gcd==1) {printf("0");return 0;}
	for(i=a/gcd;;i++){
		t=1ll*i*(i+1ll);
		if(gcd*t>b&&i*gcd>a) break;
	}
	if(lcm(i*gcd,i*gcd+gcd)>lcm(a,b)) printf("0");
	else printf("%lld",1ll*i*gcd-a);
	return 0;
}
