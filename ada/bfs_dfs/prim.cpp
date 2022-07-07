#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int>> adj[],int u,int v,int wt){
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
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

    vector<int> vis(v,0);
    vector<int> key(v,INT_MAX);
    vector<int> parent(v,-1);
    parent[0]=-1;
    key[0]=0;
    int res=0;
    for(int count=0;count<v-1;count++){
        int mini=INT_MAX,u;
        for(int i=0;i<v;i++){
            if(vis[i]==0&&key[i]<mini){
                mini=key[i];
                u=i;
            }
        }
        vis[u]=1;
        res+=key[u];
        for(auto it :adj[u]){
            int ve=it.first;
            int w=it.second;
            if(vis[ve]==0&& w<key[ve]){
                key[ve]=w;
                parent[ve]=u;
            }
        }
    }
   for (int i = 1; i < v; i++) 
        cout << i << " - " << parent[i] <<" \n"; 
        cout<<" minimum cost is :"<<res;
	return 0;


}
