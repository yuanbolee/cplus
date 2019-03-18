#include "config.c"
int Search_node(struct List *L,struct node * snode){
    int i;
    struct node *p;
    if(L->Listnum==0 ) return 0;
    else{
        p=L->head;
        for(i=1;i<=L->Listnum;i++){
            if((!strcmp(snode->name,p->name)) || (snode->m==p->m)) return i;
            p=p->next;
        }
    }
    return 0;
}