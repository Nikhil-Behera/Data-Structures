#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void trvsl(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node* head;
    struct node* second;
    struct node* third;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=90;
    head->next=second;

    second->data=89;
    second->next=third;

    third->data=69;
    third->next=NULL;

    trvsl(head);
    return 0;
}
