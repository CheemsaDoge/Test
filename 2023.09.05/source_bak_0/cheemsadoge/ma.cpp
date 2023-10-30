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
int a[MAXN],tmp_a[MAXN];
int n,m;
int IN_tmp;
inline void File(){
	freopen("ma.in","r",stdin);
	freopen("ma.out","w",stdout);
}
inline void Datain()
{
	read(n);read(m);
	for(int i=1;i<=3*m+1;i++) read(IN_tmp),a[IN_tmp]++;
}
inline bool check()
{
	for(int i=1;i<=n;i++)
	{
		bool _ac;
		if(a[i]>=2)
		{
			_ac=true;
			for(int j=1;j<=n+2;j++) tmp_a[j]=a[j];
			tmp_a[i]-=2;
			for(int j=1;j<=n+2;j++) {
				if(tmp_a[j]<0) {_ac=false;break;}
				tmp_a[j]%=3;
				tmp_a[j+1]-=tmp_a[j];
				tmp_a[j+2]-=tmp_a[j];
				tmp_a[j]=0;
			}
			if(_ac) return true;
		}
	}
	return false;
}
bool ac; 
inline void Work()
{
	ac=false;
	for(int i=1;i<=n;i++)
	{
		a[i]++;
		if(check()) ac=1,write(i),pk;
		a[i]--;
	}
	if(!ac) pn;
}
int main()
{
	File();
	Datain();
	Work();
	return 0;
}
