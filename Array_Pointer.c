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
   printf("Output Array by use p.\n");
   for (i=0,j=1;i<ROW*COL+1;i++,++j){
      printf("(%2d)",*(p++));
      if (j==COL){
         printf("\n");
         j=0;
      }
   }
   printf("the end\n");
   printf("Output Array by use pa.\n");
   for(i=0;i<ROW;i++){
      for(j=0;j<COL;j++)
         printf("(%2d)",(*(pa+i))[j]);
         //also the same as pa[i][j],*(pa[i]+j),*(*(pa+i)+j)
      printf("\n");
   }
   printf("the end\n");
   printf("Output Array by use pa as ap that is error.\n");
   for(i=0;i<ROW;i++){
      for(j=0;j<COL;j++)
         printf("(%2d)",*(pa+i)[j]);//pa use as ap method
       printf("\n");
   }
   printf("the end\n");
   printf("Output Array by use pa.\n");
   for(i=0;i<ROW;i++){
      for(j=0;j<COL;j++)
      printf("(%2d)", *(pa+i)[0]+j);
      printf("\n");
   }
   printf("the end\n");
   //*ap=&Array[0][0];
   pa=Array;
   p=&Array[0][0];
   printf("The size of (char=%ld),(int=%ld),(long=%ld)\n",\
      sizeof(char),sizeof(int),sizeof(long));
   printf("The (address +1) subtract address  equal (Array=%ld),(p=%ld),(pa=%ld),(ap=%ld)\n",\
      (unsigned long)(Array+1)-(unsigned long)Array,\
      (unsigned long)(p+1)-(unsigned long)p,\
      (unsigned long)(pa+1)-(unsigned long)pa,\
      (unsigned long)(ap+1)-(unsigned long)ap);
   printf("The size of (Array[][]=%ld),(&Array=%ld),(Array=%ld)\n",\
      sizeof(Array[0][0]),sizeof(&Array),sizeof(Array));
   printf("The size of (p=%ld),(pa=%ld),(ap=%ld)\n",\
      sizeof(p),sizeof(pa),sizeof(ap));
   printf("The size of (*p=%ld),(*pa=%ld),(*ap=%ld)\n",\
      sizeof(*p),sizeof(*pa),sizeof(*ap));
   printf("NOTICE:\nThe results are different of 32bit or 64bit compiler");

}