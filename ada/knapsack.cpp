#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int  val[],int w,int n){
   int v[n+1][w+1];
    for(int i=0;i<=n;i++){
    for(int j=0;j<=w;j++){
        if(i==0||j==0){
            v[i][j]=0;
        }
        else if(wt[i-1] <= j){
            v[i][j]=max(val[i-1]+v[i-1][j-wt[i-1]],v[i-1][j]);
        }
        else{
            v[i][j]=v[i-1][j];
        }
    }
}   
return v[n][w]; 

}
int main(){
    int n;
    cin>>n;
    int w;
    cin>>w;
   int wt[n];
   for(int i=0;i<n;i++){
       cin>>wt[i];
   }
   int val[n];
   for(int i=0;i<n;i++){
       cin>>val[i];
   }
    int res=knapsack(wt,val,w,n);
    cout<<res<<endl;
    return 0;
}
