#include <bits/stdc++.h>
using namespace std;
const int MAX=100010;
int n,m,u,v,del[MAX];
int du[MAX][2];//��¼��Ⱥͳ��� 
stack <int> st;
vector <int> G[MAX];
void dfs(int now)
{
	for(int i=del[now];i<G[now].size();i=del[now])
	{ 
		del[now]=i+1;
		dfs(G[now][i]);
	}
	st.push(now);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&u,&v),G[u].push_back(v),du[u][1]++,du[v][0]++;  
    for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
    int S=1,cnt[2]={0,0}; //��¼
    bool flag=1; //flag=1��ʾ,���еĽڵ����ȶ����ڳ���,
    for(int i=1;i<=n;i++)
	{
        if(du[i][1]!=du[i][0])
        {
            flag=0;
            if(du[i][1]-du[i][0]==1/*���ȱ���ȶ�1*/) cnt[1]++,S=i;
            else if(du[i][0]-du[i][1]==1/*��ȱȳ��ȶ�1*/) cnt[0]++;
            else return puts("No"),0;
        }
    }
    if((!flag)&&!(cnt[0]==cnt[1]&&cnt[0]==1)) return !puts("No"),0;
	//������ŷ����·���ж�������Ҳ������ŷ��·�����ж�������ֱ�����"No" 
    dfs(S);
    while(!st.empty()) printf("%d ",st.top()),st.pop();
    return 0; 
}

