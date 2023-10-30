/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXL=1e5+1145;const int INF=2147483647ll;//2^31-1
/*---------------------------------pre------------------------------------*/
int nxt[4][MAXL],l[4];
char s[4][MAXL];
inline void Pre(){
    for(int num=1;num<4;++num){
        int p=0,len=l[num];
        for(int i=2;i<=len;++i){
            while(p&&s[num][i]!=s[num][p+1]) p=nxt[num][p];
            nxt[num][i]=p+=s[num][i]==s[num][p+1]?1:0;
        }
    }
    return ;
}//KMP
#define al l[a]
#define bl l[b]
#define cl l[c]
int f(int a,int b,int c){ 
    int ans=INF,p1=0;
    for(int i=1;i<=al;++i){
        while(p1&&s[b][p1+1]!=s[a][i]) p1=nxt[b][p1];
        if(s[b][p1+1]==s[a][i]) ++p1;
        if(p1==bl) {p1=-1;break;}}
    if(p1==-1){p1=0;
        for(int i=1;i<=al;++i){
            while(p1&&s[c][p1+1]!=s[a][i]) p1=nxt[c][p1];
            p1+=s[c][p1+1]==s[a][i]?1:0;
            if(p1==cl) {p1=-1;break;}}
        if(p1==-1) ans=al;
        else ans=al+cl-p1;}
	else{int p=0;
        for(int i=1;i<=al;++i){
            while(p&&s[c][p+1]!=s[a][i]) p=nxt[c][p];
            p+=s[c][p+1]==s[a][i]?1:0;
            if(p==cl) {p=-1;break;}}
		if(p!=-1){int p2=p;
            for(int i=p1+1;i<=bl;++i){
                while(p2&&s[c][p2+1]!=s[b][i]) p2=nxt[c][p2];
                p2+=s[c][p2+1]==s[b][i]?1:0;
                if(p2==cl) {p2=-1;break;}}
            if(p2==-1) ans=al+bl-p1;
            else ans=al+bl+cl-p1-p2;}
		else ans=al+bl-p1;}
    return ans;
}
#undef al
#undef bl
#undef cl
int qq[3]={1,2,3};
int main() {
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);	
    while(scanf("%s%s%s",s[1]+1,s[2]+1,s[3]+1)==3){
	int ans=INF;
	for(int i=1;i<=3;i++) l[i]=strlen(s[i]+1);
	Pre();
	do ans=min(ans,f(qq[0],qq[1],qq[2])); while(next_permutation(qq,qq+3)); 
	printf("%d\n",ans);}
	return 0;
}
//968
