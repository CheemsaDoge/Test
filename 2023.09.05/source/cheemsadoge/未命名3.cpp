#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 200050
#define maxn 100000000
int t[N*35],ls[N*35],rs[N*35],cnt,n,ans,tot;
struct A {
    int l,r,p,c;
}a[N];
struct P {
    int p,flg,id;
    P() {}
    P(int p_,int f_,int id_) :
        p(p_),flg(f_),id(id_) {}
}d[N<<1];
bool cmp(const P &x,const P &y) {
    if(x.p==y.p) return x.flg<y.flg;
    return x.p<y.p;
}
void update(int l,int r,int x,int v,int &p) {
    if(!p) p=++tot;
    t[p]+=v; 
    if(l==r) return ;
    int mid=(l+r)>>1;
    if(x<=mid) update(l,mid,x,v,ls[p]);
    else update(mid+1,r,x,v,rs[p]);
}
int qk(int l,int r,int k,int p) {
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(k<=t[ls[p]]) return qk(l,mid,k,ls[p]);
    else return qk(mid+1,r,k-t[ls[p]],rs[p]);
}
int main() {
    int pad,pfi,pmod,prd,cad,cfi,cmod,crd,lad,lfi,lmod,lrd,rad,rfi,rmod,rrd;
    register int i;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&n,&pad,&pfi,&pmod,&prd,&cad,&cfi,&cmod,&crd,&lad,&lfi,&lmod,&lrd,&rad,&rfi,&rmod,&rrd);
    a[1].p=pfi%pmod;
    a[1].c=cfi%cmod;
    a[1].l=lfi%lmod;
    a[1].r=rfi%rmod;
    // if(a[1].l>a[1].r) swap(a[1].l,a[1].r);
    // d[++cnt]=P(a[1].l,1,1);
    // d[++cnt]=P(a[1].r+1,2,1);
    // d[++cnt]=P(a[1].p,3,1);
    // printf("i=%d, l=%d r=%d p=%d c=%d\n",1,a[1].l,a[1].r,a[1].p,a[1].c);
    for(i=2;i<=n;i++) {
        a[i].p=(1ll*a[i-1].p*prd+pad+i)%pmod;
        a[i].c=(1ll*a[i-1].c*crd+cad+i)%cmod;
        a[i].l=(1ll*a[i-1].l*lrd+lad+i)%lmod;
        a[i].r=(1ll*a[i-1].r*rrd+rad+i)%rmod;
        // if(a[i].l>a[i].r) swap(a[i].l,a[i].r);
        // printf("i=%d, l=%d r=%d p=%d c=%d\n",i,a[i].l,a[i].r,a[i].p,a[i].c);
        // d[++cnt]=P(a[i].l,1,i);
        // d[++cnt]=P(a[i].r+1,2,i);
        // d[++cnt]=P(a[i].p,3,i);
    }
    for(i=1;i<=n;i++) {
        if(a[i].l>a[i].r) swap(a[i].l,a[i].r);
        d[++cnt]=P(a[i].l,1,i);
        d[++cnt]=P(a[i].r+1,2,i);
        d[++cnt]=P(a[i].p,3,i);
    }
    // puts("-----------------------------------");
    int now=0,root=0;
    sort(d+1,d+cnt+1,cmp);
    for(i=1;i<=cnt;i++) {
        // printf("i=%d, p=%d flg=%d id=%d\n",i,d[i].p,d[i].flg,d[i].id);
        if(d[i].flg==1) {
            now++;
            update(0,maxn,a[d[i].id].c,1,root);
        }else if(d[i].flg==2) {
            now--;
            update(0,maxn,a[d[i].id].c,-1,root);
        }else {
            if(now>=d[i].id) {
                (ans+=qk(0,maxn,now-d[i].id+1,root))%=19921228;
            }
        }
    }
    printf("%d\n",ans);
}
