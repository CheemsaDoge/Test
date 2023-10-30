/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=2e6+114514;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("NOT POSSIBLE")
#define pnw puts("NOT UNIQUE")
/*---------------------------------pre------------------------------------*/
char in[MAXN];
int n;

void Datain(){
	read(n);
	if(!(n%2))
	{
		pn;exit(0);
	}
	char _in;
	_in=(char)getchar();
	while(_in==' '||_in=='\n')
		_in=(char)getchar();
	for(int i=1;i<=n;i++)
	{
		in[i]=_in;
		_in=(char)getchar();
	}
}
int mid,half;
bool ac;
int ans;
void Work(){
	mid=(n>>1)+1;
	half=(n>>1);
	bool tmpd=true;
	for(int i=2;i<=mid;i++)
	{
		if(in[i]!=in[i+half])
		{
			tmpd=false;
			break;
		}
	}
	if(tmpd)
	{
		ac=true;
		ans=1;
	}
	tmpd=true;
	bool once=false;
	if(in[1]==in[mid+1]&&in[mid]==in[n])
	{
		for(int i=1;i<=mid-1;i++)
		{
			if(in[i+once]!=in[i+mid]&&once)
			{
				tmpd=false;
				break;
			}
			if(in[i+once]!=in[i+mid])
			{
				ans=i;
				once=true;
			}
		}
		if(ac&&tmpd){
			pnw;exit(0);
		}
		if(tmpd) ac=true;
		if(tmpd&&ans==0) ans=mid;
	}
	tmpd=true;
	once=false;
	if(in[1]==in[mid])
	{
		for(int i=1;i<=mid-1;i++)
		{
			if(in[i]!=in[i+half+once]&&once)
			{
				tmpd=false;
				break;
			}
			if(in[i]!=in[i+half+once])
			{
				ans=i+half+once;
				once=true;
			}
		}
		if(ac&&tmpd){
			pnw;exit(0);
		}
		if(tmpd) ac=true;
		if(tmpd&&ans==0) ans=n;
	}
	once=false;
	if(ans==0) pn;
	else{
		for(int i=1;i<=half;i++)
		{
			if(i==ans) once=true;
			putchar(in[i+once]);
		}
	}
	return;
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	Datain();
	Work();
	return 0;
}
