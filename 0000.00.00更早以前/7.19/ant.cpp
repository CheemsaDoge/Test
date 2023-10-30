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
#define ul unsigned long long
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
ul n;
ul ans=0,ans_num=0; 
inline void dfs(ul depth,ul temp,ul num,ul up){
	if(depth>=16||temp>n) return;
	if(num>ans_num){
		ans=temp;
		ans_num=num;
	}
	if(num==ans_num&&ans>temp) ans=temp;
	for(ri i=1;i<=up;i++){
		if(temp*p[depth]>n)
			break;
		dfs(depth+1,temp*=p[depth],num*(i+1),i);
	}
	return;
}
int main()
{
//	freopen("ant.in","r",stdin);
//	freopen("ant.out","w",stdout);
	read(n);
    dfs(0, 1, 1, 35);
    printf("%llu\n", ans);
}


