#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void bfs(vector<int> adj[],int v){
    int s;
    cout<<"enter source vertex : ";
    cin>>s;
    queue<int> q;
    int visited[v];
    for(int i=0;i<v;i++){
        visited[i]=0;
    }
    visited[s]=1;
    q.push(s);
    while(! q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int i=0;i<adj[node].size();i++){
            if(visited[adj[node][i]]==0){
               visited[adj[node][i]]=1;
                q.push(adj[node][i]);

            }
        }
    }

}

int main(){
    int v;
    cin>>v;
    vector<int> adj[v];
   addEdge(adj, 0, 1);
   addEdge(adj, 0, 2);
   addEdge(adj, 1, 3);
   addEdge(adj, 1, 4);
   addEdge(adj, 2, 4);
   addEdge(adj, 3, 4);
   addEdge(adj, 3, 5);
   addEdge(adj, 4, 5);
   
   bfs(adj,v);
    return 0;
}