#include<stdio.h>
#define ROW 10  //array row
#define COL 10  //array column
void main(){
   int i,j;
   int Array[ROW][COL];//array
   int *p=&Array[0][0];// pointer of int
   int (*pa)[COL];  //int pointer of array
   int *ap[ROW];  //array of pointer
   pa=Array;

   //array=arr;
   //init Array
   for(i=0;i<ROW;i++)
      for(j=0;j<COL;j++)
         Array[i][j]=10*i+j;
   
   for (i=0,j=1;i<ROW*COL+4;i++,++j){
      printf("(%2d)",*(p++));
      if (j==COL ){
         printf("\n");
         j=0;
      }
   }
   printf("the end\n");
   for(i=0;i<ROW;i++){
      for(j=0;j<COL;j++)
         printf("(%2d)",(*(pa+i))[j]);
      printf("\n");
   }
   //also the same as p[i][j],*(p[i]+i),*(*(p+i)+j)
   printf("the end\n");
   for(i=0;i<ROW;i++){
      for(j=0;j<COL;j++)
         printf("(%2d)",*(pa+i)[j]);
       printf("\n");
   }
   *ap=&Array[0][0];

}