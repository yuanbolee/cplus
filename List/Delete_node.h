#include "config.c"

int Delete_node(struct List *L,struct node *dnode){
    int delnum,i;
    struct node *p;
    delnum=Search_node(L,dnode);
    if(delnum>0){
        if (delnum==1){
            if(L->Listnum==1){
                Destroy_List(L);
                return true;
            }
            p=L->head;
            L->head=L->head->next;
        }
        if(L->Listnum==delnum && (delnum!=1)){
            p=L->tail;
            L->tail=L->tail->link;
        }
        if((L->Listnum>delnum) && (delnum!=1) ){
            p=L->head;
            for(i=1;i<=L->Listnum;i++){
                if (i==delnum) break;
                p=p->next;
            }
        }
        p->link->next=p->next;
        p->next->link=p->link;
        L->Listnum--;
        free(dnode);
        free(p);
        puts("List delete sucess!");
        return delnum;
    }else{
        puts("List not have same node,delete node is not exist.");
        return false;
    }
}