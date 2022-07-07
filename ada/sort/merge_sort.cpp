#include<bits/stdc++.h>
using namespace std;
 

void merge(int arr[],int l,int m,int h){
    int n1=m-l+1;
    int n2=h-m;
    int le[n1],r[n2];
    for(int i=0;i<n1;i++)
    le[i]=arr[l+i];
    for(int i=0;i<n2;i++)
    r[i]=arr[m+1+i];

    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(le[i]<=r[j]){
            arr[k]=le[i];
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=le[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h)
{
	if (l < h) {
		int m = l + (h - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, h);

		merge(arr, l, m, h);
	}
}
int main(){
    int n;
    cin>>n;
    clock_t t;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%1000;
        cout<<arr[i]<<" ";
    }
    t=clock();
    mergeSort(arr,0,n-1);
    t=clock()-t;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"time taken is:" <<(double)t/CLOCKS_PER_SEC;
    return 0;
}