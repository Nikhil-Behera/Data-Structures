#include<iostream>
#include<algorithm>
using namespace std;

void input(int* arr,int n){
    cout<<"Now enter the numbners which have to be added:  "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<" number: "<<endl;
        cin>>arr[i];
    }
}

void probe_wo(int* probe_arr,int* arr,int n){
    for(int i=0;i<n;i++){
        int item = arr[i];
        int loc = item % n;

        probe_arr[loc] = item ;
    }
}

void display(int* arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
}

int main(){
    int n;
    cout<<"Enter how many numbers you want to enter: "<<endl;
    cin>>n;

    //int arr[n]={0};
    int* arr = new int[n]();
    //int probed_arr[n]={0};
    int* probed_arr = new int[n](); // Initializes all elements to 0


    input(arr,n);
    cout<<endl;
    cout<<"Your array is: "<<endl;
    display(arr,n);

    probe_wo(probed_arr,arr,n);

    cout<<endl;
    cout<<"Your probed array is: "<<endl;
    display(probed_arr,n);

    return 0;
}