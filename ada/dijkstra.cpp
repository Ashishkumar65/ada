#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt){
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
}
vector<int> dijkstra(vector<pair<int,int>> adj[],int s,int v){
    vector<int> dis(v,INT_MAX);
    vector<int> vis(v,0);
    dis[s]=0;
    for(int i=0;i<v-1;i++){
        int mini=INT_MAX;
        int u;
        for(int i=0;i<v;i++){
            if(vis[i]==0 && dis[i]<mini){
                mini=dis[i];
                u=i;
            }
        }
        vis[u]=1;
        for(auto x:adj[u]){
            int ve=x.first;
            int we=x.second;
           
                dis[ve]=min(dis[ve],dis[u]+we);
            
        }
    }

    
    return dis;
    
}

int main(){
    int v;
    cin>>v;
    vector<pair<int,int>> adj[v];
    addEdge(adj,0 ,1 ,5 );
    addEdge(adj,0 ,2 ,8 );
    addEdge(adj, 1,2 , 10);
    addEdge(adj, 1, 3,15 );
    addEdge(adj,2 ,3 ,20 );
    addEdge(adj,4,5,10);
    int s;
    cin>>s;
    vector<int> ans=dijkstra(adj,s, v);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}