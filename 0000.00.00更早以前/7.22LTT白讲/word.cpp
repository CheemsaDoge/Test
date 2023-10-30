#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ll long long
#define ri register int
#define rl register long long
int T,n,ans,num;
ll rd[27];
ll cd[27];
char sr[2000];
void initialize()
{
	ans=0;num=0;
	memset(rd,0,sizeof(rd));
	memset(cd,0,sizeof(cd));
}
int main()
{
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	read(T);
	while(T--)
	{
		initialize();
		read(n);
		for(ri i=1;i<=n;i++)
		{
			scanf("%s",&sr);
			rd[sr[0]-'a']++;
			cd[sr[strlen(sr)-1]-'a']++;
		}
		for(ri i=0;i<=25;i++)
		{
			if(rd[i]!=cd[i]) ans++;
			if(rd[i]!=0||cd[i]!=0)num++;
		}
		if((num==1&&ans==0)||(num>2&&ans<=2)||(num==2&&ans<2))	printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
		
	}
}
