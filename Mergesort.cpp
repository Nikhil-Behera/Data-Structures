#include<iostream>
using namespace std;
class merge_sort{
   
    public:
        void arr_input(int* arr,int n){
            for(int i=0;i<n;i++){
                cout<<"Enter the "<<i+1<<" element: "<<endl;
                cin>>arr[i];
            }
        }

        void display(int* arr,int n){
            for(int i=0;i<n;i++){
                cout<<arr[i]<<"\t";
            }
        }

        void MergeSort(int* arr,int low,int high){
            if(low<high){
                int mid = (low+high)/2 ;
                MergeSort(arr,low,mid);
                MergeSort(arr,mid+1,high);
                Merge(arr,low,mid,high);
            }
        }

        void Merge(int* arr,int low,int mid,int high){
            int h=low;
            int i=0;
            int j= mid+1;
            int b[high-low+1];
            while(h <= mid && j <= high){
                if(arr[h] < arr[j]){
                    b[i]=arr[h];
                    h=h+1;
                }
                else{
                    b[i]=arr[j];
                    j = j+1;
                }
                i=i+1;
            }
            if(h>mid){
                for(int k=j;k<=high;k++){
                    b[i]=arr[k];
                    i=i+1;
                }
            }
            else{
                for(int k=h ; k<=mid ;k++){
                    b[i]=arr[k];
                    i=i+1;
                }
                for(int k=low ; k<=high ;k++){
                    arr[k]=b[k-low];
                }
            }
        }
};
int main(){
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    int arr[n];
    int low=0;
    int high= n-1;
    
    
    merge_sort arr1;
    arr1.arr_input(arr,n);
    cout<<endl;

    cout<<"The original array is: "<<endl;
    arr1.display(arr,n);
    cout<<endl;

    cout<<"The sorted array is :"<<endl;
    arr1.MergeSort(arr,low,high);
    arr1.display(arr,n);
    return 0;
} 