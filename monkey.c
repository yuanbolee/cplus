#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define StrN 100

struct node {
    char name[StrN];
    int m;
    struct node *next,*link;
};
struct List{
    struct node *head,*tail;
    int Listnum;
};

int Search_node(struct List *L,struct node dnode){
    int i;
    struct node *p;
    if(L->Listnum==0 ) return 0;
    else{
        p=L->head;
        for(i=0;i<L->Listnum;i++){
            if( !strcmp(dnode.name,p->name) && (dnode.m==p->m)){
                return (i+1);break;
            }
        }
    }
    return 0;
}

void initlist(struct List *L,int n){
    int i,num;
    char pname[StrN] ;
    struct node *p,*plink;
    
    plink=NULL;
    if(n==1){
        L->head=(struct node *)malloc(sizeof(struct node));
        if(L->head!=NULL){
            strcpy(L->head->name,"start");
            L->head->m=0;
            L->head->next=NULL;
            L->head->link=NULL;
            L->tail=L->head;
            L->Listnum=1;
        }
        else L->Listnum=0;
    }
    if(n>1){
        for (i=0;i<n;i++){
            p=(struct node *)malloc(sizeof(struct node));
            if(p){
                printf("Input node(%d) of name:",i+1);
                scanf("%s",pname);
                printf("Input node(%d) of m:",i+1);
                scanf("%d",&num);
                strcpy(p->name,pname);
                p->m=num;
                if(Search_node(L,*p)>0){
                    i--;
                    printf("List have same node!\n");
                    continue;
                }
                if(i==0) {
                    L->head=p;
                    L->Listnum=1;
                    plink=p;
                    }
                else if(i==n-1){
                    L->tail=p;
                    plink->next=p;
                    p->next=L->head;
                    p->link=plink;
                    L->Listnum++;
                }
                else{
                    p->link=plink;
                    plink->next=p;
                    plink=p;
                    L->Listnum++;
                }
    
            }
        }
    }
}

int Insert_node(struct List *L,struct node *inode){
    return 0;
}

int Delete_node(struct List *L,struct node dnode){
    return 0;
}
int Sort_List(struct List *L){
    return 0;
}
int Print_List(struct List *L){
    int i;
    struct node *p;
    if(L->Listnum==0) return 0;
    p=L->head;
    printf("Print List:\n");
    for(i=0;i<L->Listnum;i++,p=p->next)
        printf("Node%i is (%s,%d)\n",i+1,p->name,p->m);
    free(p);
    return 1;
}
int Destroy_List(struct List *L){
    int i;
    struct node *p;
    if(L->Listnum==0) exit(0);
    p=L->tail;
    printf("Print List:\n");
    for(i=0;i<L->Listnum;i++,p=p->link) 
        free(p);
    L->head=NULL;
    L->tail=NULL;
    L->Listnum=0;
    return 0;
}


int main(int argc,char *arg[]){
    struct List L;
    int n;
    printf("Please input num of nodes:");
    scanf("%d",&n);
    if(n>1) initlist(&L ,n);
    else exit(0);
    Print_List(&L);
    return 0;
}

