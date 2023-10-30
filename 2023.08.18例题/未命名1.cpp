/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
const int prime=1e9+7;const int val=19890604;
#define db double
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("no")
/*---------------------------------pre------------------------------------*/

//int has(char *in)
//{
//	int len=int(strlen(in));
//	int ans=0;
//	for(int i=0;i<len;i++){
//		ans=int(1ll*ans*val%prime);
//		ans=int((1ll*ans+in[i])%prime);
//	}
//	return ans;
//}
//inline void sread(char *in){
//	register int len=0;
//	char a=char(getchar());
//	while(!((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))) a=char(getchar());
//	while(((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))) in[len++]=a,a=char(getchar());
//}
string in;
unordered_map<string,bool>h;
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n,sum;
	read(n);
	sum=n;
	while(n--){
		cin>>in;
		if(h.find(in)!=h.end()) sum--;
		else h[in]=true;
	}
	write(sum);
}
