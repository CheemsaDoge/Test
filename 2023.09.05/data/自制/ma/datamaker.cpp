/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=500;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("NO")
/*---------------------------------pre------------------------------------*/

inline void File(){
	freopen("ma.in","w",stdout);
}

int main()
{
	srand(int(time(0)));
	int OUT_tmp;
	File();
	int n=rand()%400+1;
	int m=rand()%1000+1;
	write(n),pk,write(m),pc;
	for(int i=1;i<=m*3+1;i++)
	{
		OUT_tmp=rand()%n+1;
		write(OUT_tmp),pk;
	}
	pc;
	return 0;
}
