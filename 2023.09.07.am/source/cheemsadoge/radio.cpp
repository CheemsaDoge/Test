/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=2e6+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n,ans;
int maxn;
inline int max(const int a,const int b) {return a>b?a:b;}
int prefix_function(string s) {
	int _n = (int)s.length();
	vector<int> pi(_n);
	for (int i = 1; i < _n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
		maxn=max(maxn,i-j+1);
	}
	return maxn;
}
string s;
inline void Datain()
{
	read(n);
	if(n==1)
	{
		puts("1");
		return;
	}
//	char _in;
//	_in=(char)getchar();
//	while(_in==' '||_in=='\n')
//		_in=(char)getchar();
//	for(int i=0;i<n;i++)
//	{
//		s[i]=_in;
//		_in=(char)getchar();
//	}
	cin>>s;
	write(prefix_function(s));
}


int main()
{
	freopen("radio.in","r",stdin);
	freopen("radio.out","w",stdout);
	Datain();
	return 0;
}
