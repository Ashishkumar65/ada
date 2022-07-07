#include<bits/stdc++.h>
using namespace std;
void insert_sort(int arr[],int n){
    for(int i=1;i<n;i++){
      int current=arr[i];
      int j=i-1;
      while(arr[j]>current&& j>=0){
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=current;
    }
}
int main(){
    int n;cin>>n;
    int arr[n];
    clock_t t;
    t=clock();
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insert_sort(arr,n);
    t=clock()-t;
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"time "<<(double)t/CLOCKS_PER_SEC;
    return 0;
}