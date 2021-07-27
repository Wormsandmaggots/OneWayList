#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *next;
    int x;
};
struct list{
    struct node *head;
};
void print(const struct list *l){
    if (l==NULL)
        return;
    struct node * i;
    for (i=l->head; i; i=i->next)
        printf("%d ", i->x);
    printf("\n");
}

int len(const struct list *l){
    if (l==NULL)
        return -1;
    int size=0;
    struct node * i;
    for (i=l->head; i; i=i->next, size++);
    return size;
}
void clear(struct list *list) {
    if(list == NULL || list->head == NULL)
        return;
    struct node *temp = list->head->next;
    for(struct node *i = list->head; list->head!= NULL;i=i->next) {
        struct node *temp = list->head->next;
        free(list->head);
        list->head = temp;
    }
}
struct node *createElement(int x)
{
    struct node *ret=malloc(sizeof(struct node));
    if(ret==NULL)
        return ret;
    ret->x=x;
    ret->next=NULL;
    return ret;
}
int push_front(struct list *list,struct node *node)
{
    if(list==NULL||node==NULL)
        return 1;
    node->next=list->head;
    list->head=node;
    return 0;
}
int push_back(struct list *list,struct node *node)
{
    if(list==NULL||node==NULL)
        return 1;
    struct node *last=list->head;
    for (struct node *i=last;i!=NULL;i=i->next) {
        last=i;
    }
    if(last!=NULL)
        last->next=node;
    else
        list->head=node;

    return 0;
}
struct node *pop_back(struct list *list)
{
    if(list==NULL)
        return NULL;
    struct node *temp;
    if(len(list)==1)
    {
        temp=list->head;
        list->head=NULL;
        return temp;
    }
    for (struct node  *i = list->head; i->next->next!=NULL ; i=i->next) {
        temp=i->next;
    }
    struct node *temp2=temp->next;
    temp->next=NULL;
    return temp2;
}
struct node *pop_front(struct list *list)
{
    if(list==NULL||list->head==NULL)
        return NULL;
    struct node *temp=list->head;
    list->head=list->head->next;
    return temp;
}
void insert(struct list *list,struct node *node,int index)
{
    if(list==NULL||node==NULL||index<0||index>len(list))
        return ;
    int counter=0;
    struct node *temp=list->head;
    struct node *prev=NULL;
    while(counter!=index)
    {
        counter++;
        prev=temp;
        temp=temp->next;
    }
    if(prev!=NULL)prev->next=node;
    else
        list->head=node;
    node->next=temp;
}
void del(struct list *list ,int index)
{
    if(list==NULL||index<0||index>len(list))
        return ;
    int counter=0;
    struct node *temp=list->head;
    struct node *prev=NULL;
    while(counter!=index)
    {
        counter++;
        prev=temp;
        temp=temp->next;
    }
    if(prev!=NULL)
        prev->next=temp->next;
    else
        list->head=temp->next;
    free(temp);
}
struct node *back(struct list *list)
{
    if(list==NULL)
        return NULL;
    struct node *temp;
    if(len(list)==1)
    {
        temp=list->head;
        list->head=NULL;
        return temp;
    }
    for (struct node  *i = list->head; i->next->next!=NULL ; i=i->next) {
        temp=i->next;
    }
    struct node *temp2=temp->next;
    return temp2;
}
void split(struct list *list,struct list *list1,struct  list *list2)
{
    if(list==NULL||list1==NULL||list2==NULL)
        return ;
    int counter=0;
    int length=len(list);
    struct node *temp=list->head;
    struct node *prev=NULL;
    while(counter!=length)
    {
        if(counter%2==0)
        {
            if(list1->head!=NULL)
            {
                list1->head=temp;
            }
            else
            {
                back(list1)->next=temp;
            }
            temp=temp->next;
            temp->next=NULL;
        }
        else
        {
            if(list1->head!=NULL)
            {
                list1->head=temp;
            }
            else
            {
                back(list1)->next=temp;
            }
        }
        counter++;
        struct node *temp2=temp->next;
        temp->next=NULL;
        temp=temp2;
    }
}

int main(void) {

    //Tworzenie i inicjalizacja listy
    struct list my_list;
    my_list.head = NULL;

    //Dodawanie elementów na początek listy
    for(int i=0; i<5; i++)
        push_front(&my_list, createElement(i));

    print(&my_list);

    //Dodawanie elementu na konkretny indeks
    insert(&my_list, createElement(8), 2);

    print(&my_list);

    //Usuwanie elementu z konkretnego indeksu
    del(&my_list, 2);

    print(&my_list);

    clear(&my_list);

    return 0;
}
