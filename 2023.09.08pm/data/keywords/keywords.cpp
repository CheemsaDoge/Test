/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=1e6+11145;const int INF=2147483647ll;//2^31-1
#define ri register int
#define rl register long long 
#define ll long long #define pc putchar('\n')
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
//inline void sread(char *s) //fast string input 屮，又De了半小时bug发现不能用 
//{
//	char _ch=(char)getchar();
//	while(_ch<'a'||_ch>'z') _ch=(char)getchar();
//	for(int i=0;_ch>='a'&&_ch<='z';i++)
//	{
//		s[i]=_ch;
//		_ch=(char)getchar();
//	}
//}
int tr[MAXN][30];
int totr;
int endq[MAXN];//end是关键字... 
int fail[MAXN];//失配 
int n;
inline void initialize()//初始化 
{
//	for(int i=1;i<=totr;i++) endq[i]=fail[i]=0;
	totr=0;
//	queue<int>q;
//	for(int i=0;i<=26;i++)
//		if(tr[0][i]) q.push(tr[0][i]),tr[0][i]=0;
//	while(!q.empty())
//	{
//		int u=q.front();
//		q.pop();
//		for(int i=0;i<=26;i++)
//			if(tr[u][i]) q.push(tr[u][i]),tr[u][i]=0;
//	}
	memset(endq,0,sizeof(endq));
	memset(fail,0,sizeof(fail));
	memset(tr,0,sizeof(tr));
}
inline void insert(char *s)//字典树插入 
{
	ri u=0;
	for(int i=0;s[i];i++)
		if(tr[u][s[i]-'a'])	u=tr[u][s[i]-'a'];
		else tr[u][s[i]-'a']=++totr,u=totr;
	endq[u]++;
}
inline void build()//calc失配指针捏 
{
	ri u=0;
	queue<int>a;
	for(ri i=0;i<=25;i++)
		if(tr[0][i]) a.push(tr[0][i]);
	while(!a.empty())
	{
		u=a.front();
		a.pop();
		for(int i=0;i<=25;i++)
			if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],a.push(tr[u][i]);
			else tr[u][i]=tr[fail[u]][i];
	}
}

inline int query(char *t) {
	ri u=0,res=0;
	for(ri i=0;t[i];i++)
	{
		u=tr[u][t[i]-'a'];
		for(ri j=u;j&&endq[j]!=-1;j=fail[j])
			res+=endq[j],endq[j]=-1;
	}
	return res;
}
char _in[60];
char article[MAXM];//article是这么拼的。。吧。。。 
int main(){
	freopen("keywords.in","r",stdin);
	freopen("keywords.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		read(n);
		for(ri i=1;i<=n;i++)
		{
			scanf("%s",_in);
			insert(_in);
		}
		scanf("%s",article);
		build();//De了半小时bug，发现忘了写build。。。 
		write(query(article));
		pc;
		initialize();
	}
	return 0;
}
