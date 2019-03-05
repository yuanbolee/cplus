#include<stdio.h>
#define M 10  //array row
#define N 10  //array column
void main(){
   int i,j,k;
   char c;
   int arr[M][N];
   int *array;
   int (*p)[N];
   int *pp[M];
   array=&arr[0][0];
   //array=arr;
   for(i=0;i<M;i++)
      for(j=0;j<N;j++)
         arr[i][j]=10*i+j;
   for (i=0,j=1;i<M*N+4;i++,++j){
      printf("(%2d)",*(array++));
      if (j==N ){
         printf("\n");
         j=0;
      }
   }
   printf("the end\n");
   p=arr;
   for(i=0;i<M;i++){
      for(j=0;j<N;j++)
         printf("(%2d)",(*(p+i))[j]);
      printf("\n");
   }
   //also the same as p[i][j]
   printf("the end\n");
   for(i=0;i<M;i++){
      for(j=0;j<N;j++)
         printf("(%2d)",*(p+i)[j]);
       printf("\n");
   }
   *pp=&arr[0][0];

}