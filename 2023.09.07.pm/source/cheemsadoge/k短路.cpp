#include<bits/stdc++.h>
using namespace std;
inline int cmp_vec(const vector<int>&x,const vector<int>&y)
{
	int i,sx=x.size(),sy=y.size();
	for(i=0;i<min(sx,sy);i++)if(x[i]<y[i])return 1;else if(x[i]>y[i])return 0;
	return sx<sy;
}
inline int r_cmp_vec(const vector<int>&x,const vector<int>&y)
{
	int i,sx=x.size(),sy=y.size();
	for(i=0;i<min(sx,sy);i++)if(x[i]>y[i])return 1;else if(x[i]<y[i])return 0;
	return sx>sy;
}
const int Mx=50;
const int M=Mx*Mx;
int cnt,h[Mx+5],nxt[M+5],tto[M+5],val[M+5];
inline void ade(int x,int y,int v)
{
	nxt[++cnt]=h[x];
	tto[h[x]=cnt]=y;
	val[cnt]=v;
}
int n,m,T;
int ds[Mx+5],vis[Mx+5],vst[Mx+5],prv[M+5];
int top,stk[Mx+5];
struct Gr
{
	int stt,len,lstsz,lstlen;
	vector<int>pth,frbd;
	Gr(int x){stt=x;len=lstsz=lstlen=0;pth.clear();frbd.clear();}
	inline void Clr(int x){stt=x;len=lstsz=lstlen=0;pth.clear();frbd.clear();}
	friend inline bool operator < (const Gr &x,const Gr &y)
	{
		return x.len==y.len?r_cmp_vec(x.pth,y.pth):x.len>y.len;
	}
	inline int Slv()
	{
		int i,k,x,to;
		for(i=1;i<=n;i++)ds[i]=INT_MAX,vst[i]=vis[i]=0;
		for(i=1;i<=m;i++)prv[i]=0;
		for(i=0,k=lstsz=pth.size();i<k;i++)vst[x=pth[i]]=1;
		for(i=0,k=frbd.size();i<k;i++)prv[frbd[i]]=1;
		top=ds[stt]=0;
		for(;;)
		{
			for(x=0,i=1;i<=n;i++)if(!vst[i]&&(!x||ds[x]>ds[i]))x=i;
			if(!x||ds[x]==INT_MAX)break;
			vst[stk[++top]=x]=1;
			for(i=h[x],k=ds[x];i;i=nxt[i])if(!prv[i]&&ds[to=tto[i]]>k+val[i])ds[to]=k+val[i];
		}
		if(ds[T]==INT_MAX)return 0;
		for(vis[T]=1;top;top--)for(i=h[x=stk[top]],k=ds[x];i;i=nxt[i])if(!prv[i]&&ds[to=tto[i]]==k+val[i]&&vis[to])vis[x]=1,i=0;
		for(x=stt;x^T;)
		{
			pth.epb(x);
			for(i=h[x],k=ds[x],x=n+1;i;i=nxt[i])if(!prv[i]&&ds[to=tto[i]]==k+val[i]&&vis[to])ckmn(x,to);
		}pth.epb(x);
		return len=lstlen+ds[T],1;
	}
	inline void Prt()
	{
		for(int i=0,k=pth.size();i<k;i++)writenum(pth[i],i==k-1?10:'-');
	}
	inline void Out()
	{
		for(int i=0,k=pth.size();i<k;i++)cout<<pth[i]<<(i==k-1?"\n":"-");
	}
}tp(0),tpp(0);
inline int cmp_Gr(const Gr &x,const Gr &y)
{
	return x.len==y.len?cmp_vec(x.pth,y.pth):x.len<y.len;
}
int K;
priority_queue<Gr>q;
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	#endif
	int i,j,k,x,y,s;
	int kk,sm;
	n=read();m=read();
	K=read();s=read();
	T=read();
	for(i=1;i<=m;i++)x=read(),y=read(),ade(x,y,read());
	tp=Gr(s);if(tp.Slv())q.push(tp);
	for(;!q.empty()&&(--K);)
	{
		tp=q.top();q.pop();
		for(i=tp.lstsz,k=tp.pth.size()-1,sm=tp.lstlen;i<k;i++)
		{
			x=tp.pth[i];y=tp.pth[i+1];
			for(j=h[x];j;j=nxt[j])if(tto[j]==y)break;
			tpp.Clr(x);tpp.frbd.epb(j);
			tpp.lstlen=sm;sm+=val[j];
			for(j=0,kk=tp.frbd.size();j<kk;j++)tpp.frbd.epb(tp.frbd[j]);
			for(j=0;j<i;j++)tpp.pth.epb(tp.pth[j]);
			if(tpp.Slv())q.push(tpp);
		}
	}
	if(q.empty())writechar('N','o'),pc(10);else tp=q.top(),tp.Prt();
	return output;
}
