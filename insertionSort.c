#include<stdio.h>

void printArr(int* a,int n){
    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
}
void insSort(int* a,int n)
{
    for(int i=1;i<n;i++)
    {
        int k=a[i],j;
        j=i-1;
        while(a[j]>k && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;

    }
}

int main(){
    int a[]={23,4,56,9,700,99};
    int n=6;
    insSort(a,n);
    printArr(a,n);
    return 0;
}