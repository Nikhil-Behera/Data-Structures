/*This code is made to look at the functioning of the staack...*/

#include <stdio.h>
#define n 10

int stack[n];
int p=-1;

void ismt(){
    if(p==-1){
        printf("The stack is empty...\n");
    }
    else{
        printf("The stack is not empty...\n");
    }
}

void isfull(){
    if(p==n-1){
        printf("The stack is full..\n");
    }
    else{
        printf("The stack is not full..\n");
    }
}

void add(){
    if(p==n-1){
        printf("The stack id full, cannot add more elements...\n");
    }
    else{
        p++;
        printf("Enter the element: \n");
        scanf("%d",&stack[p]);
    }
}

void delete(){
    if(p==-1){
        printf("Can't delete anymore items cuz stack is empty...\n");
    }
    else{
     
        printf("The deleted element is: %d",stack[p]);
        p--;
    }
}

void display(){
    if(p==-1){
        printf("The stack is empty so nothing to print.../n");
    }
    else{
        for(int i=0;i<p+1;i++){
            printf("%d ",stack[i]);
        }
    }
}

int main()
{
    int ch;

    do
    {
    printf("Menu:\n 1.Add element\n 2.Delete element\n 3.check if stack is empty\n 4.check if stack is full\n 5.display\n 6.Exit\n");
    printf("Enter your choice: \n");
    scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;

        case 2:
            delete();
            break;

        case 3:
            ismt();
            break;

        case 4:
            isfull();
            break;

        case 5:
           display();
           break;

        case 6:
            printf("Code exiting...\n");
            break;
        }
        
    } while (ch!=6);

    return 0;
}
