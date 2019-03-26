#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define StrN 100
#define bool int
#define true 1
#define false 0

struct node {
    char name[StrN];
    int m;
    struct node *next,*link;
};
struct List{
    char Lname[StrN];
    struct node *head,*tail;
    int Listnum;
};

int Search_node(struct List *L,struct node * snode){
    int i;
    struct node *p;
    if(L->Listnum==0 ) return 0;
    else{
        p=L->head;
        for(i=1;i<=L->Listnum;i++){
            if((!strcmp(snode->name,p->name)) || (snode->m==p->m)){ 
                return i;
            }
            p=p->next;
        }
    }
    return 0;
}


struct node *create_node(int i){
    int pnum;
    char pname[StrN];
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(p){
        if(i==-1){
            puts("Please input a node");
            printf("Input node name:");
            scanf("%s",pname);
            printf("Input node num:");
            scanf("%d",&pnum);
        }else{
            printf("Input node(%d) name:",i);
            scanf("%s",pname);
            printf("Input node(%d) num:",i);
            scanf("%d",&pnum);
        }
        if(pnum<=0)return NULL;
        strcpy(p->name,pname);
        p->m=pnum;
        p->next=NULL;p->link=NULL;
        return p;
    }else return NULL;
}


int Destroy_List(struct List *L){
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


void initlist(struct List *L){
    int i,n;
    struct node *p,*plink;

    int Sort_List(struct List *L,bool seril);
    plink=NULL;
    puts("Please input List name:");
    scanf("%s",L->Lname);
    printf("Please input num of nodes:");
    scanf("%d",&n);
    if(n<=0){
        puts("Input n is error.");
        return ;
    }

    if(n>=1){
        for (i=1;i<=n;i++){
            p=create_node(i);
            if(p){
                if(Search_node(L,p)>0){
                    i--;
                    puts("List have same node!");
                    free(p);
                    continue;
                }
                if(i==1) {
                    L->head=p;
                    L->Listnum=1;
                    if(n==1){
                        L->tail=p;
                        p->link=p;
                        p->next=p;
                    }
                    plink=p;
                }else{ 
                    p->link=plink;
                    plink->next=p;
                    plink=p;
                    L->Listnum++;
                    if(i==n){
                        L->tail=p;
                        p->next=L->head;
                        L->head->link=p;
                    }
                }
                //Sort_List(L,false);
            }else{
                    puts("Create List error!\nExit ");
                    //Destroy_List(L);
                    break;
                }
        }
    }
}

int Insert_node(struct List *L,struct node *inode){
    if(Search_node(L,inode)>0){
        puts("List have same node");
        return 0;
    }else{
        puts("List insert sucess!");
        L->tail->next=inode;
        inode->link=L->tail;
        inode->next=L->head;
        L->tail=inode;
        L->Listnum++;
        return 1;
    }
}

int Delete_node(struct List *L,struct node *dnode){
    int delnum,i;
    struct node *p;
    delnum=Search_node(L,dnode);
    if(delnum>0){
        if(L->Listnum==1){
            Destroy_List(L);
            return true;
        }else{
            if(delnum==1){p=L->head;L->head=L->head->next;}
            if(delnum==L->Listnum){p=L->tail;L->tail=L->tail->link;}
            if(delnum>1 && delnum<L->Listnum){
                p=L->head;
                for(i=1;i<=L->Listnum;i++,p=p->next)
                    if(i==delnum) break;
            }
            p->link->next=p->next;
            p->next->link=p->link;
            L->Listnum--;
            free(dnode);
            free(p);
            puts("List delete sucess!");
            return delnum;
        }
    }else{
        puts("List not have same node,delete node is not exist.");
        return false;
    }
}
void Swap_node(struct node *pb,struct node *pa){
    char pname[StrN];
    pa->m+=pb->m;
    pb->m=pa->m-pb->m;
    pa->m=pa->m-pb->m;
    strcpy(pname,pa->name);
    strcpy(pa->name,pb->name);
    strcpy(pb->name,pname);
}

int Sort_List(struct List *L,bool seril){
    struct node *pb,*pa;
    if(L->Listnum<=1) return 0;
    else{
        if(seril){
            pb=L->head;
            do{ pa=pb->next;
                if((pb->m)>(pa->m))Swap_node(pb,pa);
                pb=pb->next;
            }while(pa!=L->tail);
        }else{
            pa=L->tail;
            do{ pb=pa->link;
                if((pb->m)>(pa->m))Swap_node(pb,pa);
                pa=pa->link;
            }while(pb!=L->head);
        }
    return 1;
    }
}
int Print_List(struct List *L,bool reverse){
    int i;
    struct node *p;
    printf("Print List %s number is (%d):\n",L->Lname,L->Listnum);
    if(L->Listnum==0) {
        printf("List %s have no node!\n",L->Lname);
        return false;
    }else{
        switch(reverse){
            case true:
                p=L->tail;
                for(i=L->Listnum;i>0;i--,p=p->link)
                    printf("Node(%i) is (%s,%d)\n",i,p->name,p->m);
                break;
            case false:
                p=L->head;
                for(i=1;i<=L->Listnum;i++,p=p->next)
                    printf("Node(%i) is (%s,%d)\n",i,p->name,p->m);
                break;    
            case 2:
                p=L->tail;
                for(i=L->Listnum*2;i>0;i--,p=p->link)
                    printf("Node(%i) is (%s,%d)\n",i,p->name,p->m);
                break;
            case 3:
                p=L->head;
                for(i=1;i<=L->Listnum*2;i++,p=p->next)
                    printf("aNode(%i) is (%s,%d)\n",i,p->name,p->m);
                break;
            default:
                break;
        }
    }
    return true;
}


int main(int argc,char *arg[]){
    struct List La,Lb;
    struct node *p;
    int n;
    for(n=0;n<argc;n++)
        printf("(i arg is %s)",arg[n]);

    initlist(&La);
    initlist(&Lb);
    Print_List(&La,2);
    Print_List(&Lb,3);
    while(true){
        puts("\nNow is insert node.");
        p=create_node(-1);
        if(!p) {
            puts("Error of create node");
            break;
        }else if(Insert_node(&La,p)){
            Print_List(&La,true);
            Print_List(&La,false);
            break;
        }
    }
    while(true){
        puts("Now is delete node.");
        p=create_node(-1);
        if(!p) {
            puts("Error of create node");
            break;
        }else if(Delete_node(&La,p)) {
            Print_List(&La,true);
            break;
            }
    }
    Destroy_List(&La);
    return 0;
}

