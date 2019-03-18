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



#include "Create_node.h"
#include "Delete_node.h"
#include "Insert_node.h"
//
#include "Sort_List.h"
#include "Destroy_List.h"
#include "Init_List.h"

#ifndef _CF_H
#define _CF_H
#include "config.h"
#endif


int main(int argc,char *arg[]){
    struct List L;
    struct node *p;
    int n;
    printf("Please input num of nodes:");
    scanf("%d",&n);
    if(n>=1) initlist(&L ,n);
    else exit(0);
    Print_List(&L,false);
    Print_List(&L,true);
    while(true){
        puts("\nNow is insert node.");
        p=create_node(-1);
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
        p=create_node(-1);
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