void initlist(struct List *L,int n){
    int i;
    struct node *p,*plink;
    int Sort_List(struct List *L,bool seril);
    plink=NULL;

    if(n>=1){
        for (i=1;i<=n;i++){
            p=create_node(i);
            if(p){
                if(Search_node(L,p)>0){
                    i--;
                    printf("List have same node!\n");
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
                        }
                    }
            }else{
                    puts("Create node error!\nExit ");
                    //Destroy_List(L);
                    break;
                }
        }
    }
}

