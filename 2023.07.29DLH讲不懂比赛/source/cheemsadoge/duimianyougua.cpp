#include<bits/stdc++.h>
using namespace std;
#define INF (1 << 30)
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=1e6+1145;
char a[MAXN];
char b[MAXN];
int n;
int timing[30][30];
int ans;
int main() {
	freopen("duimianyougua.in","r",stdin);
	freopen("duimianyougua.out","w",stdout);	
	read(n);
	scanf("%s",a);
	scanf("%s",b);
	for(int i=0;i<strlen(a);i++) {if(a[i]!=b[i]) ans++;timing[b[i]-'A'][a[i]-'A']++;}
//	for(int i=0;i<=25;i++)
//	{
//		for(int j=0;j<=25;j++)
//		{
//			if(i==j) break;
//			int minn=min(timing[i][j],timing[j][i]);
//			if(minn=0)
//			{
//				for(int z=0;z<=25;z++)
//				{
//					if(timing[i][z]&&timing[z][j]) timing[]
//				}
//			}
//		}
//	}
	printf("%d",ans-1);
	return 0;
}
//能过样例就行(乐 
