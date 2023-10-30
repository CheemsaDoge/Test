//#include<bits/stdc++.h>
//using namespace std;
//const int maxn=510;
//const int maxm=5100;
//struct edge{
//	int form,to,next,w;
//}e[maxm*2];
//int n,m;
//int fa[maxn];
//int find(int x){return fa[x]==x? x : fa[x]=find(fa[x]);}
//void unionn(int a,int b){fa[find(a)]=find(b);}
//int cnt=0;
//inline void add(int u,int v,int w){
//	cnt++;
//	e[cnt].form=u;
//	e[cnt].to=v;
////	e[cnt].next=last[u];
////	last[u]=cnt;
//	e[cnt].w=w;
//}
//inline bool cmp(edge &a,edge &b){
//	return a.w>b.w;
//}
//int st,en;
//double ans=1e10;
//int a,b;
//int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++) fa[i]=i;
//	for(int i=1,u,v,w;i<=m;i++){
//		cin>>u>>v>>w;
//		add(u,v,w);
//		unionn(u,v);
//	} 
//	cin>>st>>en;
//	if(find(st)!=find(en)){
//		cout<<"IMPOSSIBLE";
//		return 0;
//	}
//	sort(e+1,e+1+cnt,cmp);
//	for(int i=1;i<=m;i++){
//		for(int k=1;k<=n;k++) fa[k]=k;
//		for(int j=i;j<=m;j++){
//			int u=e[j].form,v=e[j].to;
//			unionn(u,v);
//			if(find(st)==find(en)){
//				double tmp=(1.0*e[i].w)/(1.0*e[j].w);
//				if(tmp<ans) a=e[i].w,b=e[j].w,ans=tmp;
//				break;
//			}
//		}
//	} 
//	if(a/b*b==a){
//		cout<<a/b;
//	}
//	else cout<<a/__gcd(a,b)<<"/"<<b/__gcd(a,b);
//	return 0;
//} 

/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=8e5+10;const int MAXN=2e5+1145;const int INF=2147483647ll;
#define pn puts("IMPOSSIBLE")
#define pg putchar('\\')
#define re register
/*---------------------------------pre------------------------------------*/
int n,m,fa[1010],s,t,rn,cnt,ansnum,vis[1010];
double ans=50000;
struct edge {int u,v,w;}e[10100];
struct anss {int maxx,minn;}aa[200000];
int getf(int a) {return fa[a]==a?a:fa[a]=getf(fa[a]);} 
int cmp(edge a,edge b) {return a.w<b.w;}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n),read(m);
    for(re int i=1;i<=n;++i)    fa[i]=i,vis[i]=1;
    for(re int i=1;i<=m;++i){
        int u,v,w;
        read(u),read(v),read(w);
        e[i].u=u,e[i].v=v,e[i].w=w;
        int fu=getf(u),fv=getf(v);
        if(fu!=fv)  fa[fu]=fv;
    }
    read(s);read(t);
    if(getf(s)!=getf(t)) {pn;return 0;}
    int fs=getf(s);
    for(re int i=1;i<=n;++i)
        if(getf(i)!=fs) vis[i]=0; 
    for(re int i=1;i<=n;++i)    fa[i]=i;    
    sort(e+1,e+m+1,cmp);
    for(re int i=1;i<=m;++i){
        if(!vis[e[i].u]||!vis[e[i].v])  continue; 
        for(re int j=1;j<=n;++j)    fa[j]=j;
        for(re int j=i;j>=1;j--){  
            int u=e[j].u,v=e[j].v;
            if(!vis[u]||!vis[v])    continue;
            int fu=getf(u),fv=getf(v);
            if(fu!=fv){
                fa[fu]=fv;
                int fs=getf(s),ft=getf(t);
                if(fs==ft){  
                    aa[++cnt]=(anss){e[i].w,e[j].w};
                    break;   
                } 
            }
        }
    }
    for(re int i=1;i<=cnt;++i){   
        if(((double)aa[i].maxx/(double)aa[i].minn)<ans){
            ans=((double)aa[i].maxx/(double)aa[i].minn);
            ansnum=i;
        } 
    }
    if((aa[ansnum].maxx%aa[ansnum].minn)==0){ 
        write(aa[ansnum].maxx/aa[ansnum].minn);
    }
    else{
        int a1=aa[ansnum].maxx/__gcd(aa[ansnum].maxx,aa[ansnum].minn);
        int a2=aa[ansnum].minn/__gcd(aa[ansnum].maxx,aa[ansnum].minn);
        write(a1);pg;write(a2);
    }
    return 0;
}
