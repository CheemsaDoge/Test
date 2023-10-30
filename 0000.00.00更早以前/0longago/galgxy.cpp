#include<iostream>
#include<fstream>
using namespace std;
int gap[1000][10000]={0};
int n,m;
void add(int k,int x,int y){
	if(k==1) {
		gap[x][y]=0;
	//	if(dfs(1)==1)  return "NO";
	//	else return "YES";
	}if(k==2) {
		for(int i=1;i<=10000;i++)
		gap[x][i]=0;
    }
   // if(k==3){
    //	for(int i=1;i<=)
	//}
	
}
bool vst[10000];
int main(){
	ifstream fin("galaxy.in");
	ofstream fout("galaxy.out");
	fin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		gap[u][v]=1;
	}
	int q;
	cin>>q;
	int t,m1,n1;//m 
	for(int i=1;i<=q;i++)
	{
		cin>>t>>m1>>n1;
	     add(t,m1,n1);
	     fout<<"NO"<<endl;
	}
	fin.close();
	fout.close();
	return 0; 
}
