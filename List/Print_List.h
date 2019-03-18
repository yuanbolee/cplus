#pragma once 
#include "config.h"

int Print_List(struct List *L,bool reverse){
    int i;
    struct node *p;
    printf("Print List number is (%d):\n",L->Listnum);
    if(L->Listnum==0) {
        printf("List have no node!\n");
        return false;
    }else{
        if(reverse){
            p=L->tail;
            for(i=L->Listnum;i>0;i--,p=p->link)
                printf("Node(%i) is (%s,%d)\n",i,p->name,p->m);
        }else{
            p=L->head;
            for(i=0;i<L->Listnum;i++,p=p->next)
                printf("Node(%i) is (%s,%d)\n",i+1,p->name,p->m);
        }
    }
    return true;
}
