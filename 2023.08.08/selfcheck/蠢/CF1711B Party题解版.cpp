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
struct Edge{int u,v;}edge[MAXN];	//�ߣ�u��v�ֱ��ʾ������������ 
struct Point{int val,stick,num;}point[MAXN]; //�㣬val��ʾ��Ȩ����������ֵ����stick��ʾ��������ı�����num��ʾ��� 
int n,m,totr,ans=INF,wans=INF,num,a,b;
bool single[MAXN]; //�ж�i��i�������ı����Ƿ�Ϊ��������ֵtrue��->single[i]��point[i].stick%2==1 
void add_edge(int u,int v){edge[++totr].u=u;edge[totr].v=v;point[v].stick++;point[u].stick++;} //�ӱ� 
queue<Point>po;
void initialize()//��ʼ�� 
{
		totr=0;ans=INF;wans=INF;
		memset(edge,0,sizeof(edge));
		memset(point,0,sizeof(point));
		memset(single,0,sizeof(single));	
}
int main() {
	Point u;
	int T;read(T);while(T--){
		initialize();//�������ݣ��ǵó�ʼ�� 
		read(n),read(m);		read(n),read(m);
		initialize();
		for(int i=1;i<=n;i++) read(point[i].val),point[i].num=i,po.push(point[i]);//��ʱ�������po���У�����ȡ�� 
		for(int i=1;i<=m;i++) read(a),read(b),add_edge(a,b);//�ӱ� 
		if(m%2==0) {printf("0\n");continue;}//���У�����ż�����ߣ������0.ע�⣺��Ҫ�Ѵ˾�����ϱ���������ǰ������������������� 
		while(!po.empty()){
			num=po.front().num;u=point[num];//��ͬ��u=po.front; 
			if(u.stick%2) {ans=min(ans,u.val);single[u.num]=1;}//�ж���������ı����Ƿ�Ϊ���� ������Ϊ�����ҵ�Ȩ��Сֵ����ans 
			po.pop();
		}
		for(int i=1;i<=m;i++) if((!single[edge[i].v])&&(!single[edge[i].u])) wans=min(wans,point[edge[i].u].val+point[edge[i].v].val);
		//ö�ٱߣ�������������stickΪ�������򽫶����Ȩ��Ӵ���wans��ȡ��С
		printf("%d\n",min(ans,wans));//�����Сֵ 
	}
}
