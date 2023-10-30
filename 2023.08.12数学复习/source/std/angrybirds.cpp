#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define ll long long
using namespace std;
int T,n,m,e[20],g[20][20],f[524288];
double x[20],y[20];
bool pan(double x,double y){
    return abs(x-y)<(1e-6); 
}
int main(){
	freopen("angrybirds.in", "r", stdin);
	freopen("angrybirds.out", "w", stdout);
	scanf("%d",&T);
	e[0]=1;
	fo(i,1,19) e[i]=e[i-1]*2; 
	while(T--){
		scanf("%d%d",&n,&m);
		fo(i,1,n)
			scanf("%lf %lf",&x[i],&y[i]);
		memset(g,0,sizeof g);
        fo(i,1,n){
            fo(j,i+1,n){
            	double a,b;
            	int t;
                if(pan(x[i],x[j]))continue;
                a=(y[j]/x[j]-y[i]/x[i])/(x[j]-x[i]);
                if(a>=0)continue;
                b=y[i]/x[i]-a*x[i];
                t=0;
                fo(k,1,n) if(pan(a*x[k]+b,y[k]/x[k])) t+=e[k-1];
                g[i][++g[i][0]]=t;
            }
		}
		memset(f,127,sizeof f);
		f[0]=0;
		fo(i,0,e[n]-1)
			fo(j,1,n)
				if(!(i&e[j-1])){
					fo(k,1,g[j][0])
						f[i|g[j][k]]=min(f[i|g[j][k]],f[i]+1);
					f[i|e[j-1]]=min(f[i|e[j-1]],f[i]+1);
				}
		printf("%d\n",f[e[n]-1]);
	}
}
