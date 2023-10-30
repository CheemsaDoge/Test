#include<iostream>
#include<fstream>
using namespace std;
struct ED{
	int nxt,to,w;
}e[100001];
int x,y;
int x1=-0x7fffffff;
//int gap[2501][2500]={0};
int num=0;
int fs[2501]; 
int hd[2501]={0};
void add(int from,int to )
{
	num++;
	e[num].to=to;
	e[num].w=fs[to];
	e[num].nxt=hd[from];
	hd[from]=num;
	return;
}
int a=0;
int ans=0;
int vst[2501]={0};
int  dfs(int x2){
	vst[x2]=1;
	int u;
	for(u=hd[x2];u;u=e[u].nxt)
	{
		int v=e[u].to;
		ans+=fs[v];
		a++;
		if(vst[v]==0 && a<=4){
		dfs(v);
		dfs(hd[e[u].to]);
		vst[x2]=0;
	    }
	    if(a==5)  {
	    	if(ans>x1) x1=ans;
		}
		a--;
		ans-=fs[v];
	}
	return x1;
}
int main(){
	ifstream fin("holiday.in");
	ofstream fout("holiday.out");
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
	{
		fin>>fs[i];
	}
     fs[1]=0;
	for(int j=1;j<=m;j++)
	{
		fin>>x>>y;
		add(x,y);
	}
	fout<<dfs(1);
	//fout<<x1;
	fin.close();
	fout.close();
	return 0;
}
