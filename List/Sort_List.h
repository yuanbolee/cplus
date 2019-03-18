
#pragma once 
#include "config.h"


void Swap_node(struct node *pb,struct node *pa){
    char pname[StrN];
    pa->m+=pb->m;
    pb->m=(pa->m)-(pb->m);
    pa->m=(pa->m)-(pb->m);
    strcpy(pname,pa->name);
    strcpy(pa->name,pb->name);
    strcpy(pb->name,pname);
}

int Sort_List(struct List *L,bool seril){
    struct node *pb,*pa;
    if(L->Listnum<=1) return 1;
    if(seril){
        pb=L->head;
        do{ pa=pb->next;
            if((pa->m)>(pb->m))Swap_node(pb,pa);
            pb=pb->next;
        }while(pa!=L->tail);
    }else{
        pa=L->tail;
        do{ pb=pa->link;
            if((pa->m)>(pb->m))Swap_node(pb,pa);
            pa=pa->link;
        }while(pb!=L->head);
    }
    return 0;
}