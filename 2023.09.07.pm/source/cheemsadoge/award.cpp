/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
#define pc putchar('\n')
#define pk putchar(' ')
const int MAXN=114,MAXM=5141,MOD=31011;
/*---------------------------------pre------------------------------------*/
struct Edge {int x,y,v;}tp[MAXM],mst[MAXM];
vector<Edge> edge[MAXM]; 
int cmp(Edge a,Edge b) {return a.v<b.v;}
bool is[MAXM];
int bcj[MAXN],bel[MAXN];
void init(int a) {for(int i=1;i<=a;i++) bcj[i]=i;}
int rt(int a)
{
    if(bcj[a]==a) return a;
    return bcj[a]=rt(bcj[a]);
}
bool uni(int a,int b)
{
    int p=rt(a),q=rt(b);
    if(p==q) return true;
    bcj[p]=q;
    return false;
}
int n,deg[MAXN][MAXN],g[MAXN][MAXN],mat[MAXN][MAXN];
int treecnt()
{
    int i,j,k,ans=1;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            while(mat[j][i])
            {
                int div=mat[i][i]/mat[j][i];
                for(k=i;k<n;k++) mat[i][k]=int((mat[i][k]-1ll*mat[j][k]*div%MOD+MOD)%MOD);
                swap(mat[i],mat[j]);
                ans*=-1;
            }
            if(mat[i][i]==0) return 0;
        }
        ans=int(1ll*ans*mat[i][i]%MOD);
    }
    return (ans+MOD)%MOD;
}
int main()
{
	int a,b,i,j,k,tl=0,tmp=0,cnt=0;
    read(a);read(b);
    init(a);
    for(i=0;i<b;i++) read(tp[i].x),read(tp[i].y),read(tp[i].v);
    sort(tp,tp+b,cmp);
    for(i=0;i<b;i++)
    {
        if(tp[i].v!=tmp) tl++,tmp=tp[i].v;
        edge[tl].push_back(tp[i]);
        if(uni(tp[i].x,tp[i].y)) continue;
        is[tl]=1,mst[cnt]=tp[i],mst[cnt++].v=tl;
    }
    if(cnt!=a-1)
    {
        puts("0");
        return 0;
    }
    int ans=1;
    for(i=1;i<=tl;i++)
    {
        if(!is[i]) continue;
		init(a);
        int siz=(int)edge[i].size();
		n=0;
		for(j=0;j<cnt;j++)
		{
			if(mst[j].v==i) continue;
			uni(mst[j].x,mst[j].y);
		}
		for(j=1;j<=a;j++)
		{
			if(bcj[j]==j) bel[j]=++n;
		}
		for(j=1;j<=a;j++) bel[j]=bel[rt(j)];
        for(j=0;j<siz;j++)
        {
            int bx=bel[edge[i][j].x],by=bel[edge[i][j].y];
            deg[bx][bx]++,deg[by][by]++;
            g[bx][by]++,g[by][bx]++;
        }
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
                mat[j][k]=deg[j][k]-g[j][k];
        ans=ans*treecnt()%MOD;
        for(j=0;j<siz;j++)
        {
            int bx=bel[edge[i][j].x],by=bel[edge[i][j].y];
            deg[bx][bx]--,deg[by][by]--;
            g[bx][by]--,g[by][bx]--;
        }
    }
    write(ans);
    return 0;
}
