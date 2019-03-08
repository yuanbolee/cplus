#include<stdio.h>
union check{
    int i;
    char ch;
} ;
void main(){
    union check c;
    c.i=1;
    if (c.ch==1){
        printf("Little Endian");
    }
    else{
        printf("Big Endian");
    }
    


}