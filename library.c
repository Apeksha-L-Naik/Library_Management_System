#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char title[50],author[50];
    int copy;
    int reserved;
    int reserved_copies; 
    char reserved_by[50];  
    struct node *prev;
    struct node *next;
};struct node *head,*tail;
char section[100];
int section_displayed = 0;
void add()
{
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter book title:");
    scanf("%s",new->title);
    printf("\nEnter book author:");
    scanf("%s",new->author);
    printf("\nEnter a copy:");
    scanf("%d",&new->copy);
    new->prev=0;
    new->next=0;
    if(head==0)
    {
        head=tail=new;
    }
    else{
        tail->next=new;
        new->prev=tail;
        tail=new;
    }

}
void display()
{
    struct node *temp;
    temp=head;
    if(!section_displayed && temp != NULL) {
        printf("Section: %s\n", section);
        section_displayed = 1;
    }
    while(temp->next!=0)
    {
        printf("title:%s,author:%s,copy:%d\n",temp->title,temp->author,temp->copy);
        if (temp->reserved == 1) {
            printf(" (Reserved by: %s for %d copies)", temp->reserved_by, temp->reserved_copies);
        }
        temp=temp->next;
    }
    printf("Book are empty\n");
}
void search(char title_name[])
{
    struct node *temp=head;
    while(temp!=NULL){
        if(strcmp(temp->title,title_name)==0){
            printf("Section: %s\n", section);
            printf("Title: %s\nAuthor: %s\nCopy: %d\n\n", temp->title, temp->author, temp->copy);
            return;
        }
        temp=temp->next;
    }
    printf("Book not found\n");
}
void checkout(char checkout_title[]) {
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, checkout_title) == 0) {
            if (temp->copy > 0) {
                temp->copy--;
                printf("Book '%s' checked out successfully.\n", temp->title);
                return;
            } else {
                printf("Sorry, '%s' is out of stock.\n", temp->title);
                return;
            }
        }
        temp = temp->next;
    }
    printf("Book not found.\n");
}
void checkIn(char checkIn_title[]){
   struct node *temp=head;
   while(temp!=0){
    if(strcmp(temp->title,checkIn_title)==0){
     temp->copy++;
     printf("Book %s checked in successfully.\n",temp->title);
     return;
    }
   }
   printf("Book is not found\n");
}
void reserve(char reserve_title[], char Name[], int copy_no) {
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, reserve_title) == 0) {
            temp->reserved = 1;
            strcpy(temp->reserved_by, Name); 
            temp->reserved_copies = copy_no; 
            printf("Book '%s' reserved by %s for %d copy(s).\n", temp->title, Name, copy_no);
            return;
        }
        temp = temp->next;
    }
    printf("Book not found\n");
}
void main()
{
    head=0;
    char titlename[50],name[50];
    int choice,n,i,c;
    while(1)
    {
        printf("Enter a choice\n");
        printf("1.add\n2.display\n3.search\n4.checkout\n5.checkIn\n6.reserve\n7.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Add a section\n");
            scanf("%s",section);
            printf("No of book\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
               add();
            }
            break;
            case 2:display();
            break;
            case 3:
            printf("Enter the title of the book to search: ");
            scanf("%s", titlename);
            search(titlename);
            break;
            case 4:
            printf("Enter the title of the book to checkout: ");
            scanf("%s", titlename);
            checkout(titlename);
            break;
            case 5:
            printf("Enter the title of the book to checkIn: ");
            scanf("%s", titlename);
            checkIn(titlename);
            break;
            case 6:
            printf("enter a book to be reserved:");
            scanf("%s",titlename);
            printf("Enter you name:");
            scanf("%s",name);
            printf("Enter the copy:");
            scanf("%d",&c);
            reserve(titlename,name,c);
            break;
            case 7:return;
            break;
            default:printf("Invalid\n");
            break;
        }
    }
}