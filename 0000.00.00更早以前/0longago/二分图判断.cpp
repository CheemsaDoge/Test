#include <bits/stdc++.h>
using namespace std;
#define MAXV 1000//����Ӧ�ø�����Ŀ�Զ�

vector<int> G[MAXV];  //ͼ 
int V;                       //������ 
int color[MAXV];  //�������ɫ ��1 or -1�� 


//����v����ɫc 
bool dfs(int v,int c){
    color[v] = c;
    //�ѵ�ǰ�������ڵĶ���ɨһ�� 
    for(int i = 0;i < G[v].size(); i++){
        //������ڶ����Ѿ���Ⱦ��ͬɫ��,˵�����Ƕ���ͼ 
        if(color[G[v][i]] == c) return false;
        //������ڶ���û�б�Ⱦɫ,Ⱦ��-c,�����ڶ����Ƿ�����Ҫ�� 
        if(color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;
    }
    //�����û���⣬˵����ǰ�����ܷ��ʵ��Ķ�������γɶ���ͼ 
    return true;
}

void solve(){
    //�����ǲ���ͨͼ������ÿ�����㶼Ҫdfsһ�� 
    for(int i = 0;i < V; i++){
        if(color[i] == 0){
            //��һ������ɫΪ 1 
            if(!dfs(i,1)){
                cout << "No" << endl;
                return;
            }
        }
    }
}
int main()
{
	
}
