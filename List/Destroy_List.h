#pragma once 
#include "config.h"

bool Destroy_List(struct List *L){
    int i;
    struct node *p,*delp;
    if(L->Listnum==0) {
        printf("do not have node!\n");
        return false;
    }
    p=L->tail;
    for(i=0;i<L->Listnum;i++) {
        delp=p;
        p=p->link;
        free(delp);
    }
    L->head=NULL;
    L->tail=NULL;
    L->Listnum=0;
    return true;
}