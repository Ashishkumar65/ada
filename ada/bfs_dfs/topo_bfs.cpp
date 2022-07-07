#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v){    
    adj[u].push_back(v);
}

void toposort(vector<int> adj[],int v){
    vector<int> indeg(v,0);
    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            indeg[adj[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0)
        q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(auto x:adj[u]){
            indeg[x]--;
            if(indeg[x]==0){
                q.push(x);
            }

        }
    }
}

int main(){
    int v;
    cout<<"enter no of vertices:";
    cin>>v;
    vector<int> adj[v];
    addEdge(adj,0, 2); 
    addEdge(adj,0, 3); 
    addEdge(adj,1, 3); 
    addEdge(adj,1, 4); 
    addEdge(adj,2, 3);  
  
    cout << "Following is a Topological Sort of\n"; 
    toposort(adj,v);

    return 0;
}