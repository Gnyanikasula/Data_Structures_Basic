#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct node* rotate(struct node* head,int x){
    
    for(int i=x;i>0;i--){

        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        struct node* temp=head->next;
        struct node* p=head;
        while(temp->next!=NULL){
            temp=temp->next;
            p=p->next;
        }
        p->next=NULL;
        newnode->data=temp->data;
        newnode->next=head;
        head=newnode;
        free(temp);

        display(head);
        
    }
    return head;
}





int main(){
    struct node* head= (struct node*)malloc(sizeof(struct node));
    struct node* second= (struct node*)malloc(sizeof(struct node));
    struct node* third= (struct node*)malloc(sizeof(struct node));
    struct node* fourth= (struct node*)malloc(sizeof(struct node));
    struct node* fifth= (struct node*)malloc(sizeof(struct node));


    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=4;
    fourth->next=fifth;
    fifth->data=5;
    fifth->next=NULL;
    

    int x=0,rollno=0;
    display(head);
    printf("Enter Your Roll No: ");
    scanf("%d",&rollno);
    x=rollno%10;
    head=rotate(head,x);
    //display(head);

    return 0;
}