/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int p=2;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int T,n,cnt0;
vector<int>a,b;
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("fear.in","r",stdin);
	freopen("fear.out","w",stdout);
	read(T);while(T--){
		a.clear();cnt0=0;read(n);
		for(int i=1;i<=n;++i){
			int x;read(x);
			if(!x) ++cnt0;
			else a.push_back(x);
		}
		while(a.size()>1){
			b.clear();
			if(cnt0) b.push_back(a[0]),--cnt0;
			for(int i=1; i<a.size();i++){
				int cj=a[i]-a[i-1];
				if(!cj) ++cnt0;
				else b.push_back(cj);
			}
			sort(b.begin(),b.end());a=b;
		}
		write(a[0]),putchar('\n');
	}
	return 0;
}
