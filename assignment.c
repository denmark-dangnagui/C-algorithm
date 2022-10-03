#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disabled:4996)
int *L;
int findKthSmallest(int L[],int n, int k){
   
   return 0;
}

void buildList(int n, int min, int max){
   L = (int*)malloc(n*sizeof(int));
   srand(time(NULL));
   for (int i = 0; i < n; i++) {
      L[i] = rand() % max + min;
   }
  
}

int main(int argc, char const *argv[])
{
   int n, i,j,temp;
   buildList(10,1,100);
   for (int j = 0; j < 10; j++) {
      printf("%d ", L[j]);
   }
   printf("\n");
   // buildList(100000,1,1000000);
    return 0;
}
