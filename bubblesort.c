#include<stdio.h>

void printArr(int* a,int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void bubbleSort(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void finalArr(int* a,int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    int a[]={1,34,56,67,456,72};
    int n=6;
    printArr(a,n);
    printf("\n");
    bubbleSort(a,n);
    finalArr(a,n);

    return 0;
}