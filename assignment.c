#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma warning(disabled:4996)
int n, tmp[100000];
LARGE_INTEGER ticksPerSec;
LARGE_INTEGER start, end, diff;
int* downHeap(int list[], int i) {
   int smaller, tmp; // 작은 수의 인덱스를 받을 변수와 , 교환을 위한 tmp변수 선언
   if (n < i * 2 && n < i * 2 + 1) // 말단 노드인지 즉, 자식노드가 있는지 확인
      return;
   smaller = i * 2; // 우선 자식노드중 왼쪽자식을 작다고 설정.
   if (i * 2 + 1 <= n) {  // 하나 더 큰 인덱스를 가진 것이 오른쪽 자식인지 체크하는 조건문 
      if (list[smaller] > list[i * 2 + 1]) // 만일 자식노드 중 왼쪽 노드보다 오른쪽 노드가 작다면
         smaller = i * 2 + 1; // 변수에 저장되는 것을 바꿔줌
   }
   if (list[i] <= list[smaller])   // 만일 list[i]의 key 값이 list[smaller] 보다 작다면 바꾸는 의미 없음
      return;
   tmp = list[i];      // 교환과정
   list[i] = list[smaller];
   list[smaller] = tmp;
   downHeap(list, smaller);  // 재귀로 올라갈 수 있을 때까지 올라감
}
int* buildList(int n, int min, int max) { // 리스트 생성 함수
   int* list = (int *)malloc(sizeof(int) * n); //리스트를 만들기 리스트 사이즈 할당
   srand(time(NULL));   //난수 
   for (int i = 1; i < n + 1; i++) {// 리스트에 난수 대입
      list[i] = rand() % max + min;
      tmp[i] = list[i];           // 이거이거이ㅓ기어기ㅓ이ㅓ이거이ㅓ기어기어기어ㅣㅓ38942378174983721904731297 이거 확인해봐바바바ㅏ바바바바바ㅏ바바바바바바바ㅏ바바바바바바바바바바바바ㅏ바바바바바바바
   }
   return list; // 리스트 반환
}
int* buildHeap(int list[], int n) { // 최소힙 만들기 위해 downHeap부름
   for (int i = n / 2; i > 0; i--) { // 전역변수 마지막 내부노드부터 역방향으로 루트까지 가게 하기위해서 이렇게 범위를 줌
      downHeap(list, i); // 각 위치에 맞게 이동할 수 있도록 downHeap 호출
   }
   return list;  // 최소힙을 만들어서 반환
}
int* inPlaceHeapSort(int list[], int k) { // 제자리 힙 정렬 + k번째로 작은 값 반환 하는 함수 
   int i, temp, cnt = 0, j = 0, count = 0;  // 필요한 변수 선언
   for (i = n; i >= 2; i--) {               // 2번째 까지 변경하면 더 교환할 일 없기 때문에 크기 n부터 2까지 반복
      cnt++;                              // k번째 값을 확인하기 위한 cnt 값 1씩 추가
      temp = list[1];                     // 아래식을 보면 n이 하나씩 줄어들게 반복문을 돌리고 있는데, 매번 제일 말단과 1번을 바꾸는 작업.
      list[1] = list[i];
      list[i] = temp;
      n--;
      if (cnt == k) {                     // 그러다보면 cnt값이 k값과 같아질 때 반복문을 나와서 시간을 단축하는 형태입니다. 
         break;
      }
      downHeap(list, 1);                  // cnt값이 k보다 작을 경우에는 계속해서 downHeap을 호출해서 정렬을 진행합니다.
   }
   printf("final %d\n", cnt);           
   return temp;                          // temp값이 맨 뒤로 가서 내림 차순으로 제자리 정렬 되는 것이므로, 맨뒤로 가는 값인 temp 값을 반환합니다.
}
int* findKthSmallest(int L[], int n, int k) {  // k번째 작은 값을 반환하기 위한 함수선언
   int answer;                            // 변수 선언
   buildHeap(L, n);                       // 최소힙 만드는 함수 호출
   for (int i = 1; i < 11; i++) {         // 
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
   int list1[85001], list2[85001], list3[85001];
   int k1[3] = { 1, 2, 3 };
   int k2[4] = { 1, 1000, 50000, 84999 };
   double time[5];
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
   list = buildList(85000, 1, 1000000);//
   for (i = 1; i < 85001; i++) {
      list1[i] = list[i];
   }
   for (i = 1; i < 85001; i++) {
      list2[i] = list[i];
   }
   for (i = 1; i < 85001; i++) {
      list3[i] = list[i];
   }
   n = 85000;
   QueryPerformanceFrequency(&ticksPerSec);
   QueryPerformanceCounter(&start);
   output[0] = findKthSmallest(list, 85000, k2[0]);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;
   time[0] = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);

   n = 85000;
   QueryPerformanceFrequency(&ticksPerSec);
   QueryPerformanceCounter(&start);
   output[1] = findKthSmallest(list1, 85000, k2[1]);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;
   time[1] = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);

   n = 85000;
   QueryPerformanceFrequency(&ticksPerSec);
   QueryPerformanceCounter(&start);
   output[2] = findKthSmallest(list2, 85000, k2[2]);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;
   time[2] = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);

   n = 85000;
   QueryPerformanceFrequency(&ticksPerSec);
   QueryPerformanceCounter(&start);
   output[3] = findKthSmallest(list3, 85000, k2[3]);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;
   time[3] = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);

   if (k2[3] == 85000) {
      output[3] = list3[1];
   }
   for (i = 0; i < 4; i++) {
      printf("result : %d  cputime%.12f\n", output[i],time[i]);
   }
   printf("\n");
   return 0;
}