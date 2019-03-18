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