#include<stdio.h>
int main(){
    int m,n,k=0;
    printf("Enter rows m: \n");
    scanf("%d",&m);
    printf("Enter col n: \n");
    scanf("%d",&n);
    int arr[m][n];
    //Taking the input of the og matrix.
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            printf("%d%d: \n",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Your enetered matrix is: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",arr[i][j]);   
        }
        printf("\n");
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                k++;
            }
        }
    }
    printf("The non 0 elements present in the matrix are: %d\n",k);
    /*arr[0][0]=m;
    arr[0][1]=n;
    arr[0][2]=k;*/
    /*for(int i=0;i<m;i++){                         /* This is for shortcut method                                                   
        for(int j=0;j<3;j++){                           jism,e naya matrix create nahi hota hai.*/
            /*if(arr[i][j]!=0){
                printf("%d\t%d\t%d",i,j,arr[i][j]);
            }
        }
        printf("\n");
    }*/

    int smatrix[k][3];
    smatrix[0][0]=m;
    smatrix[0][1]=n;
    smatrix[0][2]=k;
    int l=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                smatrix[l][0]=i;
                smatrix[l][1]=j;
                smatrix[l][2]=arr[i][j];
                l++;
            }
        }
    }
    printf("%d\t%d\t%d\n",smatrix[0][0],smatrix[0][1],smatrix[0][2]);
    for(int i=1;i<=k;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",smatrix[i][j]);
        }
        printf("\n");
    }

    //Ab simple transpose karenge...
    printf("\n");
    printf("The simple transpose of the above sparse matrix is as follows: \n");
    int st[k+1][3];
    
    int z=1;
    st[0][0]=smatrix[0][1];
    st[0][1]=smatrix[0][0];
    st[0][2]=smatrix[0][2];
    for(int j=0;j<n;j++){
        for(int i=1;i<=k;i++){
            if(smatrix[i][1]==j){
                st[z][0]=smatrix[i][1];
                st[z][1]=smatrix[i][0];
                st[z][2]=smatrix[i][2];
                z=z+1;
            }
        }
    }
    
    printf("%d\t%d\t%d\n",st[0][0],st[0][1],st[0][2]);
    for(int i=1;i<=k;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",st[i][j]);
        }
        printf("\n");
    }

    printf("\nPerforming fast transpose...");
    printf("\n");
    int total_arr[n],index_arr[n+1];
    int count =0;
    for(int j=0;j<n;j++){
        for(int i=1;i<=k;i++){
            if(smatrix[i][1]==j){
                count++;
                total_arr[j]=count;
                count=0;
            }
        }
    }
    /*for(int i=0;i<n;i++){             //check for total_arr was correct or not..
        printf("%d  ",total_arr[i]);
    }*/
    index_arr[0]=1;
    for(int i=1;i<n+1;i++){
        index_arr[i]=index_arr[i-1]+total_arr[i-1];
    }
    /*printf("\n");
    for(int i=0;i<n+1;i++){             //check for index_arr was correct or not..
        printf("%d  ",index_arr[i]);
    }*/

    int ft[k][3];
    ft[0][0]=smatrix[0][1];
    ft[0][1]=smatrix[0][0];
    ft[0][2]=smatrix[0][2];
    int loc;
    int colno;
    for(int i=1;i<=k;i++){
            colno=smatrix[i][1];
            loc=index_arr[colno];
            ft[loc][0]=smatrix[loc][1];
            ft[loc][1]=smatrix[loc][0];
            ft[loc][2]=smatrix[loc][2];
            loc++;

        }
    for(int i=0;i<=k;i++){
        for(int j=0;j<3;j++){
            printf("%d\t",ft[i][j]);
        }
        printf("\n");
    }    


    return 0;
}