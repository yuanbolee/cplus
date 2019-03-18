#include "Create_node.c"
#include "Delete_node.c"
#include "Insert_node.c"
//
#include "Sort_List.c"
#include "Destroy_List.c"
#include "Init_List.c"

#ifndef _CF_
#define _CF_
#include "config.c"
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