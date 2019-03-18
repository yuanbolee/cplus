#include "config.c"

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
        p->next=NULL;
        p->link=NULL;
        return p;
    }else return NULL;
}