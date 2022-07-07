#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[],int u,int  v){
    adj[u].push_back(v);
}

void dfs(vector<int> adj[],vector<int> &vis,stack<int> &st,int u){
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if(vis[adj[u][i]]==0)
        dfs(adj,vis,st,adj[u][i]);
    }
    st.push(u);
}


void topo_sort(vector<int> adj[],int v){
    vector<int> vis(v,0);
    stack<int> st;
    for(int i=0;i<v;i++){
        if(vis[i]==0){
            dfs(adj,vis,st,i);
        }
    }
    while(st.empty()==false){
        int u=st.top();
        cout<<u<<" ";
        st.pop();
    }
}



int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,1, 3); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 4); 
    addEdge(adj,2, 4);  
  
    cout << "Following is a Topological Sort of\n"; 
    topo_sort(adj,V);

	return 0; 
} 
