/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=35+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n1,n2;
int num1[60],num2[60];
int in;
vector<int>a1,a2;
void Datain()
{
	read(n1);
	for(int i=1;i<=n1;i++)
		read(in),num1[in]++;
	read(n2);
	for(int i=1;i<=n2;i++)
	{
		read(in);
		if(num1[in])
		{
			num1[in]--;
			n1--;
			n2--;
			i--;
		}
		else num2[in]++;
	}
	for(int i=1;i<=50;i++)
	{
		while(num1[i])
		{
			a1.push_back(i);
			num1[i]--;
		}
		while(num2[i])
		{
			a2.push_back(i);
			num2[i]--;
		}
	}
}

int main()
{
//	freopen("black.in","r",stdin);
//	freopen("black.out","w",stdout);
	Datain();
	write(abs(n2-n1));
	return 0;
}
