/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXM=23;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
ll gcd(ll a,ll b){
	if(a<b) return gcd(b,a);
	return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}
vector<long long>x[MAXM];
queue<long long>zan[MAXM];
ll m,qq,ans;
long long n;
int main() {
//	freopen("light.in","r",stdin);
//	freopen("light.out","w",stdout);	
	read(n);read(m);
	for(int i=1;i<=m;i++) 
	{
		read(qq);
		for(int j=1;j<=m;j++){
			if(x[j].empty()) break;
			for(int p=0;p<x[j].size();p++) zan[j+1].push(lcm(qq,x[j][p]));
		}
		x[1].push_back(qq);
		for(int j=2;j<=m;j++){
			if(zan[j].empty()) break;
			while(!zan[j].empty()) x[j].push_back(zan[j].front()),zan[j].pop();
		}
	}
	int temp=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<x[i].size();j++){
			ans+=temp*(n/x[i][j]);
		}
		temp=1ll*temp*(-2);
	}
	printf("%lld\n",ans);
	return 0;
}
