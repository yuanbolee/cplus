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
    struct node *head,*tail;
    int Listnum;
};

#include"Print_List.h"
#include "Init_List.h"
#include "Create_node.h"
    extern int Print_List(struct List *L,bool reverse);
    extern void Init_List(struct List *L,int n);
    extern int Search_node(struct List *L,struct node * snode);
    extern struct node *Create_node(int i);
    extern int Insert_node(struct List *L,struct node *inode);
    extern int Delete_node(struct List *L,struct node *dnode);
    extern bool Destroy_List(struct List *L);
    extern int Print_List(struct List *L,bool reverse);
int main(int argc,char *arg[]){



    struct List L;
    struct node *p;
    int n;
    printf("Please input num of nodes:");
    scanf("%d",&n);
    if(n>=1) Init_List(&L ,n);
    else exit(0);
    Print_List(&L,false);
    Print_List(&L,true);
    while(true){
        puts("\nNow is insert node.");
        p=Create_node(-1);
        if(!p) {
            puts("Error of create node");
            break;
        }else if(Insert_node(&L,p)){
            Print_List(&L,true);
            break;
        }
    }
    while(true){
        puts("Now is delete node.");
        p=Create_node(-1);
        if(!p) {
            puts("Error of create node");
            break;
        }else if(Delete_node(&L,p)) {
            Print_List(&L,true);
            break;
            }
    }
    Destroy_List(&L);
    
    return 0;
}