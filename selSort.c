#include<stdio.h>

void priArr(int* a,int n)
{
    for(int i=0;i<n;i++){
        printf(" %d",a[i]);
    }
}

void selSort(int* a,int n)
{
    int min,temp;
    for(int i=0;i<=n;i++)
    {
        min=i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int  main(){
    int a[]={34,5,6,78,89,555,29000};
    int n=7;
    selSort(a,n);
    priArr(a,n);
    return 0;
}