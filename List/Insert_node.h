#include "config.h"

int Insert_node(struct List *L,struct node *inode){
    if(Search_node(L,inode)>0){
        puts("List have same node");
        return 0;
    }else{
        puts("List insert sucess!");
        L->tail->link->next=inode;
        inode->link=L->tail;
        inode->next=L->head;
        L->tail=inode;
        L->Listnum++;
        return 1;
    }
}