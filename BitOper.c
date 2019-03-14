#include <stdio.h>
#include <ctype.h>
#include <string.h>
union Ans_bit{
    struct A{
        unsigned :4;
        unsigned a:1;
        unsigned b:1;
        unsigned c:1;
        unsigned d:1;
    };
    struct B{
        unsigned a:1;
        unsigned b:1;
        unsigned c:1;
        unsigned d:1;
        unsigned e:1;
        unsigned f:1;
        unsigned g:1;
        unsigned h:1;
    } bit;
    char ans;
};
void initAB(union Ans_bit *ab){
    (*ab).bit.a=0;(*ab).bit.b=0;
    (*ab).bit.c=0;(*ab).bit.d=0;
    (*ab).bit.e=0;(*ab).bit.f=0;
    (*ab).bit.g=0;(*ab).bit.h=0;
}
 void printAB(union Ans_bit ab){
     printf("%d",ab.bit.a);
     printf("%d",ab.bit.b);
     printf("%d",ab.bit.c);
     printf("%d",ab.bit.d);
     printf("%d",ab.bit.e);
     printf("%d",ab.bit.f);
     printf("%d",ab.bit.g);
     printf("%d\n",ab.bit.h);
 }

int main(){
    char anstr[8];
    int i;
    char c;
    union Ans_bit ab;
    initAB(&ab);

    printf("Please input ans:");
    scanf("%s",anstr);
    printf("Input string is (%8s)\n",anstr);
    for(i=0;i<8;i++){
        c=toupper(anstr[i]);
        if(isalpha(c)){
            switch(c){
                case 'A':ab.bit.a=1;break;
                case 'B':ab.bit.b=1;break;
                case 'C':ab.bit.c=1;break;
                case 'D':ab.bit.d=1;break;
                case 'E':ab.bit.e=1;break;
                case 'F':ab.bit.f=1;break;
                case 'G':ab.bit.g=1;break;
                case 'H':ab.bit.h=1;break;
                default :break;
            }
        }
    }
    printAB(ab);
    return 0;
    
}