#include<stdio.h>
#include<stdlib.h>
#define Array_N 4
void main(int argc ,char *argv[]){
    int i,j;
    char *p,**pp;
    char str[]="I am a geek!";
    char * pstr[]={"Hello,World","Monkeys like peach",
        "Standing shoulder of gaint","团结就是力量"};
    printf("%s\n",str);
    p=str;
    printf("%s\n",p);
    for(i=0;i<Array_N;i++)
        printf("%s\n",pstr[i]);
    pp=pstr+Array_N-1;
    for(i=Array_N-1;i>=0;i--)
        printf("\n%s",*(pp--));

    
}