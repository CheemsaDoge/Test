#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=1e6+1145;
char st[MAXN],c;
int tot;
inline bool is_win()
{
	if(c=='O'&&st[tot-1]!='T') return 1;
	if(c=='B'&&st[tot-1]!='O') return 1;
	if(c=='T'&&st[tot-1]!='B') return 1;
	return 0;
}
int T,n;
int main()
{
	freopen("moon,in","r",stdin);
	freopen("moon,out","w",stdout);
	read(T);
	while(T--)
	{
		read(n);tot=0;
		for(int i=1;i<=n;i++){
			scanf("%c",&c);
			while(tot!=0&&is_win())tot--;st[tot++]=c;
		}
		printf("%c\n",st[0]);
	}
	return 0;
}
