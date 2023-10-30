/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))_x=(_x<<3)+(_x<<1)+(ch^'0'),ch=getchar();_x=_x*w;}//fast input
template<typename T> inline void write(T _x){static char q[65];int cnt=0;if(_x<0)putchar('-'),_x=-_x;q[++cnt]=char(_x%10),_x/=10;while(_x)q[++cnt]=char(_x%10),_x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=1e3+10;const int MAXN=1e3+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n;
int a[60],f[3][3][20][60];
int tot;
int dfs(bool lead,bool limit,int last,int pos)
{
	if(!pos) return lead;
	if(!limit&&lead&&f[lead][limit][last][pos]) return f[lead][limit][last][pos];
	int up=limit?a[pos]:9;
	int res=0;
	for(int i=0;i<=up;i++){
		if(abs(i-last)<2) continue;
		res+=dfs(lead|i,limit&(i==up),lead?i:(i?i:13),pos-1);
	}
	if(!limit&&lead) f[lead][limit][last][pos]=res;
	return res;
}
int solve (int x)
{
	if(x<=1) return x;
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	int ans=0;
	tot=0;
	while(x) {
		a[++tot]=x%10;
		x/=10;
	}
	int up=a[tot];
	for(int i=0;i<=up;i++) ans+=dfs(i,i==up,i?i:13,tot-1);
	return ans;
}
int x,y;
int main()
{
//	freopen("windy.in","r",stdin);
//	freopen("windy.out","w",stdout);
	read(x);read(y);
	write(solve(max(x,y))-solve(min(x,y)-1));
}
