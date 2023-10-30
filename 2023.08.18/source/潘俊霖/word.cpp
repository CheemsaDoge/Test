/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=1e5+1145;const int MAXN=20000+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
map<string,int>sum;
map<string,bool>flag;
int ans,length,n,m,start=1;
string cx[MAXM],in; 
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	freopen("word.in","r",stdin);
//	freopen("word.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) cin>>in,flag[in]=true;
	read(m);
	for(int i=1;i<=m;i++)
	{
		cin>>cx[i];
		if(flag[cx[i]]) sum[cx[i]]++;
		if(sum[cx[i]]==1) ans++,length=i-start+1; //new
		while(start<=i)
		{
			if(!flag[cx[start]]) {start++;continue;}
			if(sum[cx[start]]>=2) {sum[cx[start]]--,start++;continue;}
			break;
		}
		length=min(length,i-start+1);
	}
	write(ans);pc;write(length);
	return 0;
}
//单词背诵
//1 /lt n /le 2 /times 10^5
