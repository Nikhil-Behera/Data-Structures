#include<stdio.h>
#include<string.h>
#include<ctype.h>
int n;
char stack[10];
char post[10];
int p=-1;

int precedence(char item){
    if(item=='^'){
        return 3;
    }
    else if(item=='*' || item=='/' || item =='%'){
        return 2;
    }
    else{
        return 1;
    }
}

void push(char ch){
    if(p==n-1){
        printf("Stack overflow..\n");
    }
    else{
        p++;
        stack[p]=ch;
    }
}
int pop(){
    if(p==-1){
        return -1;
    }
    else{
        return stack[p--];
        
    }
}

void Postfix(char* arr,char* post){
    int i,j;
    i=0;
    j=0;
    char item;

    
    while(arr[i]!='\0'){
    item=arr[i];
        if(item=='('){
            push(item);
        }
        else if(isdigit(item) || isalpha(item)){
            post[j++]=item;
        }
        else if(item==')'){
            while(p!=-1 && stack[p]!='('){
                post[j++]=pop();
            }
            pop();
        }
        else{
            while(p!=-1 && precedence(item)<=precedence(stack[p])){
                post[j++]=pop();
            } 
            push(item);
        }
        i++; 
    }
    while(p!=-1){
        post[j++]=pop();
    }

    post[j]='\0';

    printf("The postfix expression is: %s\n",post);
}


int main(){
    printf("Enter the length of the array: \n");
    scanf("%d",&n);
    char infi[n+1];
    
    printf("Enter the string: \n");
    scanf("%s",infi);
    
    Postfix(infi,post);

    return 0;
}