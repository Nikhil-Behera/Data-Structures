#include<stdio.h>
#include<string.h>

struct stud{
    char name[90];
    int prn;
    int rn;
};

int main(){
    struct stud stud1[5];
    for(int i=0;i<5;i++){
        printf("Enter the name of student %d: \n",i+1);
        scanf("%s",stud1[i].name);
        printf("Enter the prn of the student %d: \n",i+1);
        scanf("%d",&stud1[i].prn);
        printf("Enter the Roll No. of student %d : ",i+1);
        scanf("%d",&stud1[i].rn);
    }
    printf("Menu:\n");
    printf("1.Bubble Sort \t 2.Selection Sort \t 3.Insertion Sort\n");
    int ch;
    printf("Enter your choice: \n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Performing Bubble Sort...\n");
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(stud1[j].rn>stud1[j+1].rn){
                    int temp=stud1[j+1].rn;
                    stud1[j+1].rn=stud1[j].rn;
                    stud1[j].rn=temp;

                    int temp1=stud1[j+1].prn;
                    stud1[j+1].prn=stud1[j].prn;
                    stud1[j].prn=temp1;

                    char temp2[90];
				    strcpy(temp2,stud1[j+1].name);
				    strcpy(stud1[j+1].name,stud1[j].name);
				    strcpy(stud1[j].name,temp2);


                }
            }
        }
        printf("The list is now updated roll number wise...\n");
        for(int i=0;i<5;i++){
            printf("%d\t",stud1[i].rn);
            printf("%s\t",stud1[i].name);
            printf("%d\t",stud1[i].prn);
            printf("\n");
        }
    }

    else if(ch==2)
    {
        printf("Performing Selection Sort...\n");
        int min,temp;
        for(int i=0;i<=5;i++){
            min=i;
            for(int j=i+1;j<=5-1;j++){
                if(stud1[j].rn<stud1[min].rn){
                    min=j;
                }
            }
        if(min!=i){
            int temp;
            temp=stud1[i].rn;
            stud1[i].rn=stud1[min].rn;
            stud1[min].rn=temp;

        }
        if(min!=i){
            int temp1;
            temp1=stud1[i].prn;
            stud1[i].prn=stud1[min].prn;
            stud1[min].prn=temp1;

        }
        if(min!=i){
            char temp2[90];
            strcpy(temp2,stud1[i].name);
            strcpy(stud1[i].name,stud1[min].name);
            strcpy(stud1[min].name,temp2);

        }
        }
        for(int i=0;i<5;i++){
            printf("%d\t",stud1[i].rn);
            printf("%s\t",stud1[i].name);
            printf("%d\t",stud1[i].prn);
            printf("\n");}
    }

    else if(ch==3)
    {
       printf("Performing Insertion Sort... \n");
       for(int i=1;i<5;i++){
            int k=stud1[i].rn;
            int j=i-1;
            while(j>=0 && stud1[j].rn>k){
                stud1[j+1].rn=stud1[j].rn;
                j=j-1;
            }
            stud1[j+1].rn=k;
       } 

            for(int i=0;i<5;i++){
                int k=stud1[i].prn;
                int j=i-1;
                while(j>=0 && stud1[j].prn>k){
                    stud1[j+1].prn=stud1[j].prn;
                    j=j-1;
                }
                stud1[j+1].prn=k;
            }
            /*for(int i=0;i<5;i++){
                int k=stud1[i].name;
                int j=i-1;
                while(j>=0 && stud1[j].name>k){
                    stud1[j+1].name=stud1[j].name;
                    j=j-1;
                }
                stud1[j+1].prn=k;
            }*/

       for(int i=0;i<5;i++){
            printf("%d\t",stud1[i].rn);
            printf("%s\t",stud1[i].name);
            printf("%d\t",stud1[i].prn);
            printf("\n");}
    }
    
    
    return 0;
}

