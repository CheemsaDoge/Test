/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}//fast input
const int MAXN=1e5+1145;
const int INF=2147483647ll;//2^31-1
struct Edge{int u,v;}edge[MAXN];	//边，u、v分别表示边相连的两点 
struct Point{int val,stick,num;}point[MAXN]; //点，val表示点权（即不快乐值），stick表示与点所连的边数，num表示编号 
int n,m,totr,ans=INF,wans=INF,num,a,b;
bool single[MAXN]; //判断i与i点所连的边数是否为单（是则赋值true）->single[i]即point[i].stick%2==1 
void add_edge(int u,int v){edge[++totr].u=u;edge[totr].v=v;point[v].stick++;point[u].stick++;} //加边 
queue<Point>po;
void initialize()//初始化 
{
		totr=0;ans=INF;wans=INF;
		memset(edge,0,sizeof(edge));
		memset(point,0,sizeof(point));
		memset(single,0,sizeof(single));	
}
int main() {
	Point u;
	int T;read(T);while(T--){
		initialize();//多组数据，记得初始化 
		read(n),read(m);		read(n),read(m);
		initialize();
		for(int i=1;i<=n;i++) read(point[i].val),point[i].num=i,po.push(point[i]);//暂时将点放入po队列，方便取用 
		for(int i=1;i<=m;i++) read(a),read(b),add_edge(a,b);//加边 
		if(m%2==0) {printf("0\n");continue;}//特判：若有偶数条边，则输出0.注意：不要把此句放在上边两行输入前，否则会跳过两个输入 
		while(!po.empty()){
			num=po.front().num;u=point[num];//等同于u=po.front; 
			if(u.stick%2) {ans=min(ans,u.val);single[u.num]=1;}//判断与点相连的边数是否为单数 ，并将为单数且点权最小值存入ans 
			po.pop();
		}
		for(int i=1;i<=m;i++) if((!single[edge[i].v])&&(!single[edge[i].u])) wans=min(wans,point[edge[i].u].val+point[edge[i].v].val);
		//枚举边，若所连的两点stick为复数，则将二点点权相加存入wans并取最小
		printf("%d\n",min(ans,wans));//输出最小值 
	}
}
