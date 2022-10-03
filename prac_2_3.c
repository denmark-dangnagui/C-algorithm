#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>
#pragma warning(disable:4996)
LARGE_INTEGER ticksPerSec;
LARGE_INTEGER start, end, diff;

void insert_sort(int n, int array[]) {
   int i,j,key;
   for (i = 1; i < n; i++) { // 삽입정렬 하기위해 array[1]부터 비교하기 위해 반복문 돌리기 시작
      key = array[i];               // 키값을 설정해 키 값의 앞부분을 비교
      for (j = i - 1; j >= 0; j--) {  // 키값의 바로 앞부분부터 array[0]까지 비교 반복문 시작
         if (array[j] > key) {       // array[j] 값이 키값보다 크면 
            array[j + 1] = array[j]; //array[j+1]에 array[j]값을 넣어준다.
         }
         else {                     // 같은 수들이 배열에 겹쳐지지 않게 array[j] 값이 작거나 같으면 바뀌지 않게 break를 걸어준다.
            break;
         }
      }
      array[j + 1] = key;  // 반복문을 나오게 된다면, j값은 반복문에서 계속 작아졌고, 반복문이 끝났을 때 j값 기준으로 앞에 값자리가 key값이 들어갈 자리이므로 이렇게 공식 선언
   }
   
}
void select_sort(int n, int array[]) {
   int i,j,idx,temp,cnt;
   for (i = n - 1; i > 0; i--) { // array의 뒷부분부터 정렬하기
      temp = array[i];
      cnt = 0;
      for (j = i - 1; j >= 0; j--) {   //선택정렬을 하기위해서 temp를 활용해서 최고값을 확인, 한번만 교환하기 위해서 이런 반복문 사용
         if (temp < array[j]) {
            temp = array[j];  //기준이 되는 값의 앞에서 최고값과 인덱스값을 저장함.
            idx = j;
            cnt++;          // cnt를 통해 기준값보다 앞에 최고값이 있는지 확인
         }
      }
      if (cnt != 0) {  // 최고값이 있다면 cnt값이 1증가 하므로 두수를 바꿔줌. cnt = 0 일 경우 제자리에 있는다.
         array[idx] = array[i];
         array[i] = temp;
      }
   }
   
   
}
double cputime_insert(int n, int array[]) {         //삽입정렬 cputime을 체크하기 위한 함수
   QueryPerformanceFrequency(&ticksPerSec);
   QueryPerformanceCounter(&start);
   insert_sort(n, array);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;

   return ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
}
double cputime_select(int n, int array[]) {         //선택정렬 cputime을 체크하기 위한 함수
   QueryPerformanceFrequency(&ticksPerSec);
   QueryPerformanceCounter(&start);
   select_sort(n, array);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;

   return ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
}
void main() {
   int n, i,j,temp;
   int *array_a;
   int *array_b;
   srand(time(NULL));
   scanf("%d", &n);
   array_a = (int *)malloc(sizeof(int) * n);
   array_b = (int *)malloc(sizeof(int) * n);
   for (i = 0; i < n; i++) {
      array_a[i] = rand();
   }
   for (i = 0; i < n; i++) {
      array_b[i] = rand();
   }
   /* 역순으로 정렬할 때
   for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n; j++) {
         if (array_a[j] < array_a[j + 1]) {
            temp = array_a[j];
            array_a[j] = array_a[j + 1];
            array_a[j + 1] = temp;
         }
      }
   }
   for (i = 0; i < n - 1; i++) {
      for (j = 0; j < n; j++) {
         if (array_b[j] < array_b[j + 1]) {
            temp = array_b[j];
            array_b[j] = array_b[j + 1];
            array_b[j + 1] = temp;
         }
      }
   }
   */
   
   /* 정순으로 정렬할 때
   select_sort(n, array_a);
   insert_sort(n, array_b);
   */

   for (j = 0; j < n; j++) {
      printf("%d ", array_a[j]);
   }
   printf("\n");
   for (j = 0; j < n; j++) {
      printf("%d ", array_b[j]);
   }
   printf("\n");
   printf("%.12f sec \n", cputime_select(n, array_a));
   printf("%.12f sec \n", cputime_insert(n, array_b));

   free(array_a);
   free(array_b);
}