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
const int MAXM=2e5+1145;const int MAXN=50000+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n,ans,m;
inline int max(const int a,const int b) {return a>b?a:b;}
vector<int> prefix_function(vector<int>s) {
	int _n = (int)s.size();
	vector<int> pi(_n);
	for (int i = 1; i < _n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}
int find_occurrences(vector<int>text, vector<int>pattern) {
	int sz1 = (int)text.size(), sz2 = (int)pattern.size();
	vector <int>cur(sz1+sz2+1);
	for(int i=0;i<(int)text.size();i++)
		cur[i]=text[i];
	cur[(int)text.size()]=2;
	for(int i=1;i<=(int)pattern.size();i++)
		cur[sz1+i]=pattern[i];
	vector<int> lps = prefix_function(cur);
	for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
		if (lps[i] == sz2)
			return 1;
	}
	return 0;
}
vector<int> password;
vector<int> message[MAXN];
inline void Work()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		if(password.size()>message[i].size()) ans+=find_occurrences(password,message[i]);
		else ans+=find_occurrences(message[i],password);
	}
	write(ans);pc;
}
int tmp_n,tmp_a;
inline void Datain()
{
	read(n);read(m);
	for(int i=1;i<=n;i++)
	{
		read(tmp_n);
		for(int j=0;j<tmp_n;j++)
		{
			read(tmp_a);
			message[i].push_back(tmp_a);
		}
	}
	for(int i=1;i<=m;i++)
	{
		read(tmp_n);
		for(int j=0;j<tmp_n;j++)
		{
			read(tmp_a);
			password.push_back(tmp_a);
			write(password[j]);
		}
		Work();
	}
}

int main()
{
//	freopen("sec.in","r",stdin);
//	freopen("sec.out","w",stdout);
	vector<int>b;
	while(1)
	{
		read(tmp_a);
		b.push_back(tmp_a);
		for(int i=0;i<(int)b.size();i++)
		{
			write(b[i]),pk;
		}
		pc;
	}
	return 0;
}
