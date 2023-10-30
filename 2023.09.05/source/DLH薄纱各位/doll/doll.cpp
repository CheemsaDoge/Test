#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector> 
#define maxn 500005
#define setIO(s) freopen(s".in","r",stdin)
#define mod 19921228
#define ll long long 
using namespace std;
vector <int> G[maxn]; 
struct Node{
    int l,r,c,p; 
}node[maxn],arr[maxn]; 
int n;   
namespace DATA_Maker{
    int C[maxn],L[maxn],R[maxn],P[maxn];
    void make(int *a){
        int pa,pf,pm,pp; 
        scanf("%d%d%d%d",&pa,&pf,&pm,&pp);
        a[1] = pf % pm;
        for(int i = 2;i <= n; ++i) a[i]=((long long)a[i-1]*pp+pa+i)%pm; 
    }
    int main(){ 
        scanf("%d",&n);
        make(P); for(int i=1;i<=n;++i) node[i].p=P[i];
        make(C); for(int i=1;i<=n;++i) node[i].c=C[i];
        make(L); for(int i=1;i<=n;++i) node[i].l=L[i]; 
        make(R); for(int i=1;i<=n;++i) node[i].r=R[i]; 
    }
};     
namespace Solve{
    int hh[maxn],que[maxn],cc[maxn],cur[maxn],answer[maxn],tl[maxn],tr[maxn]; 
    struct Array{
        int A[maxn];
        int lowbit(int t){ return t&(-t); }
        void update(int pos,int delta){ while(pos<maxn) A[pos]+=delta,pos+=lowbit(pos);  }
        void add(int l,int r,int k){ update(l,k),update(r+1,-k); }
        int query(int x){ if(!x) return 0; int sum=0; while(x>0) sum+=A[x],x-=lowbit(x); return sum;  }
    }T;                                        
    void solve(int x,int y,int l,int r){
        if(l>r||x>y) return;                          
        if(l==r){  
            for(int i=x;i<=y;++i) answer[que[i]]=cc[l]; 
            return; 
        }
        int mid=(l+r)>>1,p=0,q=0,kk=x-1;
        for(int i=mid+1;i<=r;++i) 
            for(int j=0;j<G[i].size();++j)  T.add(node[G[i][j]].l,node[G[i][j]].r,1); 
        for(int i=x;i<=y;++i) {
            int delta=cur[que[i]]+T.query(node[que[i]].p);   
            if(delta>=que[i]) tr[++q]=que[i];           
            else tl[++p]=que[i],cur[que[i]]=delta;   
        }
        for(int i=mid+1;i<=r;++i) 
            for(int j=0;j<G[i].size();++j) T.add(node[G[i][j]].l,node[G[i][j]].r,-1);
        for(int i=1;i<=p;++i) que[++kk]=tl[i];
        for(int i=1;i<=q;++i) que[++kk]=tr[i]; 
        solve(x,x+p-1,l,mid),solve(y-q+1,y,mid+1,r); 
    }
    int main()         
    {
        //=======================================ÀëÉ¢»¯
        int cnt=0,mx=0; 
        for(int i=1;i<=n;++i)
        {
            hh[++cnt]=node[i].l;
            hh[++cnt]=node[i].r;
            hh[++cnt]=node[i].p; 
        }
        sort(hh+1,hh+1+cnt); 
        for(int i=1;i<=n;++i) 
        { 
            node[i].p=lower_bound(hh+1,hh+1+cnt,node[i].p)-hh;
            node[i].l=lower_bound(hh+1,hh+1+cnt,node[i].l)-hh;
            node[i].r=lower_bound(hh+1,hh+1+cnt,node[i].r)-hh; 
            if(node[i].l>node[i].r)swap(node[i].l,node[i].r); 
        }  
        for(int i=1;i<=n;++i) cc[i]=node[i].c;
        sort(cc+1,cc+1+n); 
        for(int i=1;i<=n;++i) node[i].c=lower_bound(cc+1,cc+1+n,node[i].c)-cc; 
        //========================================ÀëÉ¢Íê±Ï
        for(int i=1;i<=n;++i) G[node[i].c].push_back(i),mx=max(mx,node[i].c); 
        for(int i=1;i<=n;++i) que[i]=i; 
        solve(1,n,0,mx); 
        long long tmp=0; 
        for(int i=1;i<=n;++i) tmp+=answer[i],tmp%=mod; 
        printf("%lld",tmp);  
    }
}; 
int main(){
    freopen("doll.in","r",stdin);
    freopen("doll.out","w",stdout);
    DATA_Maker::main(); 
    Solve::main(); 
    return 0; 
}

