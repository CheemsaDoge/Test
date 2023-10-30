/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
inline void bread(bool &x){
	int _ch=(int)getchar()-'0';
	while(!(_ch==1||_ch==0)) _ch=getchar()-'0';
	x=_ch;
}
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=5e5+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n,m;

vector<bool> password;
vector<bool> message;

int tmp_n,tmp_a;
int totr;
int tr[MAXN][2];
int endq[MAXN],sum[MAXN];
inline void insert(vector<bool>s)
{
	int u=0;
	int len=(int)s.size();
	for(int i=0;i<len;i++)
	{
		u=tr[u][s[i]]=tr[u][s[i]]?tr[u][s[i]]:++totr;
		sum[u]++;
	}
	sum[u]--;
	endq[u]++;
}
int query(vector<bool>s)
{
	int ans=0;
	int u=0,len=(int)s.size();
	for(int i=0;i<len;i++)
	{
		if(!(u=tr[u][s[i]])) return ans;
		ans+=endq[u];
	}
	ans+=sum[u];
	return ans;
}

inline void Datain()
{
	read(n);read(m);
	for(int i=1;i<=n;i++)
	{
		read(tmp_n);
		message.clear();
		for(int j=1;j<=tmp_n;j++)
		{
			read(tmp_a);
			message.push_back(tmp_a);
		}
		insert(message);
	}
	for(int i=1;i<=m;i++)
	{
		read(tmp_n);
		password.clear();
		for(int j=1;j<=tmp_n;j++)
		{
			read(tmp_a);
			password.push_back(tmp_a);
		}
		write(query(password));pc;
	}
}

int main()
{
	freopen("sec.in","r",stdin);
	freopen("sec.out","w",stdout);
	Datain();
	return 0;
}
