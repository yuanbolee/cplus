#include<stdio.h>
#include<stdlib.h>
#define M 8
#define N 8
void main(){
   int i,j,k;
   char c;
   int arr[M][N];
   int *array;
   int (*p)[N];
   int *pp[N];
   array=&arr[0][0];
   array=arr;
   for(i=0;i<M;i++)
      for(j=0;j<N;j++)
         arr[i][j]=10*i+j;
   for (i=0;i<M*N+4;i++)
      printf("(%d)",*(array++));
   printf("the end\n");
   p=arr;
   for(i=0;i<M;i++)
      for(j=0;j<N;j++)
         printf("(%d)",(*(p+i))[j]);
   printf("the end\n");
   for(i=0;i<M;i++)
      for(j=0;j<N;j++)
         printf("(%d)",*(p+i)[j]);
  // for(int k=0;k<500;k++)
   //	printf("The num is %d;char is %c.\n",k,k);
}