#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsrec(vector<int> adj[],vector<int> &visited,int s){
    visited[s]=1;
    cout<<s<<" ";
    for(int i=0;i<adj[s].size();i++){
        if(visited[adj[s][i]]==0){
            dfsrec(adj,visited,adj[s][i]);
        }
    }
}

void dfs(vector<int> adj[],int v,int s){
    vector<int> visited(v,0);
    cout<<"dfs order is : ";
    dfsrec(adj,visited,s);
    int flag=1;
    for(int i=0;i<v;i++){
       if(visited[i]==0){
           flag=0;
           break;
       }
    }
    if(flag==1){
        cout<<"\ngraph is connected";
    }
    else{
        cout<<"\ngraph is dissconnected";
    }

}

int main(){
    int v;
    cout<<"enter no of vertex :";
    cin>>v;
    vector<int> adj[v];
   addEdge(adj, 0, 1);
   addEdge(adj, 1, 3);
   addEdge(adj, 1, 2);
   addEdge(adj, 2, 3);
   addEdge(adj, 4, 5);
   
   int s;
   cout<<"enter source vertex :";
   cin>>s;

   dfs(adj,v,s);
    return 0;
}