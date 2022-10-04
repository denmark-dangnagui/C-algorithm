#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disabled:4996)
int n, tmp[100000];
/*
double cputime_insert(int n, int array[]) {         //삽입정렬 cputime을 체크하기 위한 함수
   QueryPerformanceFrequency(&ticksPerSec);
   QueryPerformanceCounter(&start);

   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;

   return ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
}
*/
int* downHeap(int list[], int i) {
   int smaller, tmp; // 큰수의 인덱스를 받을 변수와 , 교환을 위한 tmp변수 선언
   if (n < i * 2 && n < i * 2 + 1) // 말단 노드인지 즉, 자식노드가 있는지 확인
      return 0;
   smaller = i * 2; // 우선 자식노드중 왼쪽자식을 크다고 설정.
   if (i * 2 + 1 <= n) {  // 하나 더 큰 인덱스를 가진 것이 오른쪽 자식인지 체크하는 조건문 
      if (list[smaller] > list[i * 2 + 1]) // 만일 자식노드 중 왼쪽 노드보다 오른쪽 노드가 크다면
         smaller = i * 2 + 1; // 변수에 저장되는 것을 바꿔줌
   }
   if (list[i] <= list[smaller])   // 만일 Heap[i]의 key 값이 Heap[bigger] 보다 크다면 바꾸는 의미 없음
      return 0;
   tmp = list[i];      // 교환과정
   list[i] = list[smaller];
   list[smaller] = tmp;
   downHeap(list, smaller);  // 재귀로 올라갈 수 있을 때까지 올라감
   return 0;
}
int* buildList(int n, int min, int max) {
   int* list = (int *)malloc(sizeof(int) * n);
   srand(time(NULL));
   for (int i = 1; i < n + 1; i++) {
      list[i] = rand() % max + min;
      tmp[i] = list[i];
   }
   return list;
}
int* buildHeap(int list[], int n) { // 
   for (int i = n / 2; i > 0; i--) { // 전역변수 마지막 내부노드부터 역방향으로 루트까지 가게 하기위해서 이렇게 범위를 줌
      downHeap(list, i); // 각 위치에 맞게 이동할 수 있도록 downHeap 호출
   }
   return list;
}
int* inPlaceHeapSort(int list[], int k) { // 제자리 힙 정렬
   int i, temp, cnt = 0, j = 0, count = 0;
   for (i = n; i >= 2; i--) {
      cnt++;
      temp = list[1];
      list[1] = list[i];
      list[i] = temp;
      n--;
      if (cnt == k) {
         break;
      }
      downHeap(list, 1);
   }  // 계속해서 반복하여, n을 줄여줬기 때문에, 점차 큰 값들은 다운힙에 고려되는 키 값들은 줄어들기 때문에, 결국 루트힙에는 최소값이 들어가는 제자리 힙 정렬 완성
   printf("final %d\n", cnt);
   return temp;
}
int* findKthSmallest(int L[], int n, int k) {
   int answer;
   buildHeap(L, n);
   for (int i = 1; i < 11; i++) {
      printf("%d ", L[i]);
   }
   printf("\n");
   answer = inPlaceHeapSort(L, k);
   printf("\n");
   return answer;
}
int main() {
   int output[5], i;
   int* list;
   int list1[100001], list2[100001], list3[100001];
   int k1[3] = { 1, 2, 3 };
   int k2[4] = { 1, 100, 99900, 99999 };
   list = buildList(10, 1, 100);
   for (i = 1; i < 11; i++) {
      printf(" %d", list[i]);
   }
   printf("\n");
   for (i = 1; i < 11; i++) { 
      list1[i] = list[i];
   }
   for (i = 1; i < 11; i++) {
      list2[i] = list[i];
   }
   n = 10;
   output[0] = findKthSmallest(list, 10, k1[0]);
   n = 10;
   output[1] = findKthSmallest(list1, 10, k1[1]);
   n = 10;
   output[2] = findKthSmallest(list2, 10, k1[2]);
   if (k1[2] == 10) {
      output[2] = list2[1];
   }
   for (i = 0; i < 3; i++) {
      printf(" %d", output[i]);
   }
   printf("\n\n");
   //buildList(100000, 1, 1000000);
   list = buildList(100000, 1, 1000000);
   for (i = 1; i < 100001; i++) {
      list1[i] = list[i];
   }
   for (i = 1; i < 100001; i++) {
      list2[i] = list[i];
   }
   for (i = 1; i < 100001; i++) {
      list3[i] = list[i];
   }
   n = 100000;
   output[0] = findKthSmallest(list, 100000, k2[0]);
   n = 100000;
   output[1] = findKthSmallest(list1, 100000, k2[1]);
   n = 100000;
   output[2] = findKthSmallest(list2, 100000, k2[2]);
   n = 100000;
   output[3] = findKthSmallest(list3, 100000, k2[3]);
   if (k2[3] == 100000) {
      output[3] = list3[1];
   }
   for (i = 0; i < 4; i++) {
      printf(" %d", output[i]);
   }
   printf("\n");
   return 0;
}