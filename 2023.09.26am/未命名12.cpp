#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using i128=__int128_t;
#define all(x) x.begin(),x.end()
#define mem0(x) memset(x,0,sizeof(x))
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define errorf(...) fprintf(stderr, __VA_ARGS__) 
#define endl '\n'
#define pb push_back

int read(){
    int f=1,x=0;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*f;
}
template <class T>
T read(){
    T f=1,x=0;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return x*f;
}
template <class T>
void write(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}

const int K = 1e4;
int cntAll[K];
int cntSingle[K],tag[K];

int main(){
    int n=read(),k=read(),p=read();
    ll ans = 0;
    int now = 0;
    for(int i=0;i<n;i++){
        int a=read(),b=read();
        ans += cntAll[a];
        cntAll[a]++;

        if(b<=p)now++;
        else{
            if(tag[a]!=now){
                tag[a]=now,cntSingle[a]=0;
            }
            ans -= cntSingle[a];
            cntSingle[a]++;
        }
    }

    printf("%lld\n",ans);
    return 0;
}
