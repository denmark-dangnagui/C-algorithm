// 비트행렬에서 1의 수 세기 + 실행시간 측정
// n x n 배열로서 난수 함수를 이용하여 초기화
// 각행은 비오름차순 난수를 발생시키며 다음 행이 그전 행의 90% 이상이어야 한다.
// 이 과정에서 배열 내 1의 총수, 즉 ki (0 < i ≤ n – 1) 값의 총합을 kTotal 변수에 누적한다
// 주함수는 아래 세 가지 n값에 대해 느린 버전, 빠른 버전 함수 쌍을 각각 호출하고 그 결과를 인쇄한다
// kTotal = 실제 1의 총수, ones = 프로그램이 계산한 1의 총수 , cputime
// 각각 느린버전과 빠른버전을 n값을 3000,1000,2000으로 실행간 값을 구한다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#pragma warning(disable:4996)
LARGE_INTEGER ticksPerSec;			// cputime을 체크하기 위해서 전역변수로 선언. 그 이유는 cputime을 체크하기 위한 함수를 따로 두면서 함수의 가독성을 높이기 위해 전역변수를 사용함.
LARGE_INTEGER start, end, diff;		// cputime을 체크하기 위해서 전역변수로 선언. 그 이유는 cputime을 체크하기 위한 함수를 따로 두면서 함수의 가독성을 높이기 위해 전역변수를 사용함.

int countOnesButSlow(int **a, int n) {      // 문제에서 제시 된 느린 버전 알고리즘 n^2[n제곱]이라는 실행시간을 가지게 되는 함수
	int i, j, count = 0;
	for (i = 0; i < n; i++) {             // i를 통해 행을 구분해 주는 반복문
		j = 0;                         // 0열부터 검사를 하기 위해
		while ((j < n) && (a[i][j] == 1)) { // i행에서 j열에서 연속된 1의 개수를 세기 위한 반복문
			count++;                        // 1의 개수 저장
			j++;                     // 다음 열 검색
		}
	}                               // 이중 반복문 사용하면서 n^2[n제곱] 이라는 실행시간을 가짐.
	return count;                           // 총 1의 개수 반환
}
int countOnes(int **a, int n) {             // n이라는 실행시간을 가지는 함수
	int i = 0, j, count = 0;
	for (j = n - 1; i < n; j--) {         // n-1 열부터 0열까지 검사하는 반복문
		if ((a[i][j] == 1)) {
			count += j + 1;               // n-1 열부터 체크하면서 1이 나올 때 count 값에 1이 나온 열의 인덱스값+1을 count에 더해줌
			i++;                     // 1이 나오면 그 다음 열을 보지 않고 그 다음 행으로 넘어감
			j = j + 1;                  // 문제에서 제시된 행렬은 각 행에서 1이 연속적으로 나오고 행의 인덱스 값이 커질 때마다 그 다음 행의 1의 갯수가 같거나 적기 때문에 현재 행에서 현재 1이 체크된 열의 인덱스값을 j에 저장하여 그 다음행의 j열부터 부터 체크 하며 시간 줄이기
		}
		if (a[i][0] == 0)               // 만일 i행 0열의 수가 0이라면 그 행부터 그 후에 1은 절대 나오지 않기 때문에 반복문을 탈출한다.
			break;           // 또한 실행시간 0초를 허용하지 않기 때문에 이 if 조건문이 위의if ((a[i][j] == 1)) 조건문 보다 아래에 있는 것.
	}
	return count;
}
	// 기존 1번 문제에서 썼던 함수이기 때문에 빠른 함수의 경우 1의 개수를 제대로 검출하지는 못할 확률이 높다. 난수로서 1번 문제와는 달리 1이 연속적으로 안나올 수 있기 때문.


double cputime_fast(int **x, int n) {			// 빠른 함수를 사용한 cputime을 체크하기 위한 함수
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	countOnes(x, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;

	return ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
}

double cputime_slow(int **x, int n) {			// 느린 함수를 사용한 cputime을 체크하기 위한 함수
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	countOnesButSlow(x, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;

	return ((double)diff.QuadPart / (double)ticksPerSec.QuadPart);
}

int main() {					// 저는 컴퓨터 사양을 고려해 문제에서 제시된 크기의 1/10으로 크기를 낮추어 진행하겠습니다.
	int **a = NULL;				// a,b,c 세가지만 동적할당을 하면 되는 이유는 총 1000,2000,3000 이렇게 3가지 경우로 1의 개수를 세고 cputime을 체크하면 됨으로 세가지로만 동적할당을 진행함.
	int **b = NULL;
	int **c = NULL;
	int n1, n2, n3, i, j, slow = 0, fast = 0, count = 0, check = 0;    //n1,n2,n3 : 각각 크기를 저장하기 위한 변수 , i,j : 반복문을 돌리기 위한 기본 변수 , slow,fast : 각각 느린 함수 빠른 함수 1의 개수를 저장하기 위한 변수 , count ,check : 문제에서 제시된 것 처럼 난수를 사용해 비오름차순으로 행렬을 만들고 또한 ki + 1이 ki의 90% 이상이어야 함으로 이전 행에 대한 1의 개수를 check로 두고 count를 통해 90%이상으로 개수를 넘기기 위해서 사용하는 변수
	int kTotal1 = 0, kTotal2 = 0, kTotal3 = 0;   // 각각 실제 1의 총수
	double cputime_n1, cputime_n2, cputime_n3, cputime_n4, cputime_n5, cputime_n6;  // 각각 cputime을 계산하기 위한 변수

	n1 = 3000;   // 저는 컴퓨터 사양을 고려해 문제에서 제시된 크기의 1/10으로 크기를 낮추어 진행하겠습니다.
	n2 = 1000;
	n3 = 2000;

	a = (int **)malloc(n1 * sizeof(int *));  // 행을 위한 동적할당
	b = (int **)malloc(n2 * sizeof(int *));  // 행을 위한 동적할당
	c = (int **)malloc(n3 * sizeof(int *));  // 행을 위한 동적할당

	for (i = 0; i < n1; i++) {
		a[i] = (int *)malloc(n1 * sizeof(int));  // 열을 위한 동적할당
	}
	for (i = 0; i < n2; i++) {
		b[i] = (int *)malloc(n2 * sizeof(int));  // 열을 위한 동적할당
	}
	for (i = 0; i < n3; i++) {
		c[i] = (int *)malloc(n3 * sizeof(int));  // 열을 위한 동적할당
	}


	srand(time(NULL));   //난수를 위한 함수

	for (i = 0; i < n1; i++) {  // 크기가 3000인 함수  행을 반복시키기 위한 반복문
		check = count;		    // 이전 행에 대하여 체크 된 1의 개수 값을 check에 저장
		count = 0;				// 매 행마다 1의 개수를 0으로 초기화 하여 기준에 부합하게 하기 위해 0으로 둠.
		for (j = 0; j < n1; j++) {  // 열에 대한 반복문
			a[i][j] = rand() % 2;  // 0 , 1 둘 중 하나의 난수를 저장하게 하기 위한 함수 사용
			if (a[i][j] == 1) {  // 1이라면
				count++;         // count 값을 올림.
				kTotal1++;		 // 실제 1의 갯수를 저장하기 위한 값
			}
			if (i == 0) {		// 0 행 일 경우 이전 행이 없기 때문에 문제에 제시된 조건에 부합하게 하기 위하여
				if (((0.9 * n1) <= count && count <= n1)) {  // 문제에서 제시된 조건인  0.9n ≤ k0 ≤ n 적용
					break;									// 위 조건에 부합 될 때 0 행에 대한 반복문을 멈추어서 이 범주 안에 들어왔을 때 멈추고 다음 행으로 진행
				}
			}
			else {				// 0행이 아닌 경우 문제에 제시된 조건에 부합하게 하기 위하여
				if (((0.9 * check) <= count && count <= check)) { // 문제에서 제시된 조건인 0.9k0 ≤ k1 ≤ k0
					break;									// 위 조건에 부합 될 때 행에 대한 반복문을 멈추어서 이 범주 안에 들어왔을 때 멈추고 다음 행으로 진행
				}
			}
		}
	}

	for (i = 0; i < n2; i++) {     // 크기가 1000인 함수 행을 반복시키기 위한 반복문
		check = count;		       // 이전 행에 대하여 체크 된 1의 개수 값을 check에 저장
		count = 0;				   // 매 행마다 1의 개수를 0으로 초기화 하여 기준에 부합하게 하기 위해 0으로 둠.
		for (j = 0; j < n2; j++) { // 열에 대한 반복문
			b[i][j] = rand() % 2;  // 0 , 1 둘 중 하나의 난수를 저장하게 하기 위한 함수 사용
			if (b[i][j] == 1) {    // 1이라면
				count++;		   // count 값을 올림.
				kTotal2++;		   // 실제 1의 갯수를 저장하기 위한 값
			}
			if (i == 0) {          // 0 행 일 경우 이전 행이 없기 때문에 문제에 제시된 조건에 부합하게 하기 위하여
				if (((0.9 * n2) <= count && count <= n2)) {    // 문제에서 제시된 조건인  0.9n ≤ k0 ≤ n 적용
					break;		   // 위 조건에 부합 될 때 0 행에 대한 반복문을 멈추어서 이 범주 안에 들어왔을 때 멈추고 다음 행으로 진행
				}
			}
			else {					// 0행이 아닌 경우 문제에 제시된 조건에 부합하게 하기 위하여
				if (((0.9 * check) <= count && count <= check)) {  // 문제에서 제시된 조건인 0.9k0 ≤ k1 ≤ k0 적용
					break;         // 위 조건에 부합 될 때 행에 대한 반복문을 멈추어서 이 범주 안에 들어왔을 때 멈추고 다음 행으로 진행
				}
			}
		}
	}



	for (i = 0; i < n3; i++) { // 크기가 2000인 함수 행을 반복시키기 위한 반복문
		check = count;		   // 이전 행에 대하여 체크 된 1의 개수 값을 check에 저장
		count = 0;			   // 매 행마다 1의 개수를 0으로 초기화 하여 기준에 부합하게 하기 위해 0으로 둠.
		for (j = 0; j < n3; j++) { // 열에 대한 반복문
			c[i][j] = rand() % 2;  // 0 , 1 둘 중 하나의 난수를 저장하게 하기 위한 함수 사용
			if (c[i][j] == 1) {   // 1이라면
				count++;		  // count 값을 올림.
				kTotal3++;	      // 실제 1의 갯수를 저장하기 위한 값
			}
			if (i == 0) {		  // 0 행 일 경우 이전 행이 없기 때문에 문제에 제시된 조건에 부합하게 하기 위하여
				if (((0.9 * n3) <= count && count <= n3)) {    // 문제에서 제시된 조건인  0.9n ≤ k0 ≤ n 적용
					break;		   // 위 조건에 부합 될 때 0 행에 대한 반복문을 멈추어서 이 범주 안에 들어왔을 때 멈추고 다음 행으로 진행
				}
			}
			else {					// 0행이 아닌 경우 문제에 제시된 조건에 부합하게 하기 위하여
				if (((0.9 * check) <= count && count <= check)) {      // 문제에서 제시된 조건인 0.9k0 ≤ k1 ≤ k0 적용
					break;		    // 위 조건에 부합 될 때 행에 대한 반복문을 멈추어서 이 범주 안에 들어왔을 때 멈추고 다음 행으로 진행
				}
			}
		}
	}

	cputime_n1 = cputime_fast(a, n1);		// 크기가 3000인 a라는 행렬에 대한 1의 갯수 셀 때 빠른 함수에 대한 cputime 저장
	fast = countOnes(a, n1);				// 빠른 함수를 통해 1의 갯수 체크
	printf("%d %d %.12fms\n", kTotal1, fast, cputime_n1);  // 실제 1의 개수 , 빠른 함수를 통해 1의 갯수 체크한 값 , cputime 출력

	cputime_n2 = cputime_fast(b, n2);		// 크기가 1000인 b라는 행렬에 대한 1의 갯수 셀 때 빠른 함수에 대한 cputime 저장
	fast = countOnes(b, n2);				// 빠른 함수를 통해 1의 갯수 체크
	printf("%d %d %.12fms\n", kTotal2, fast, cputime_n2);  // 실제 1의 개수 , 빠른 함수를 통해 1의 갯수 체크한 값 , cputime 출력

	cputime_n3 = cputime_fast(c, n3);		// 크기가 2000인 c라는 행렬에 대한 1의 갯수 셀 때 빠른 함수에 대한 cputime 저장
	fast = countOnes(c, n3);				// 빠른 함수를 통해 1의 갯수 체크
	printf("%d %d %.12fms\n", kTotal3, fast, cputime_n3);  // 실제 1의 개수 , 빠른 함수를 통해 1의 갯수 체크한 값 , cputime 출력

	cputime_n4 = cputime_slow(a, n1);		    // 크기가 3000인 a라는 행렬에 대한 1의 갯수 셀 때 느린 함수에 대한 cputime 저장
	slow = countOnesButSlow(a, n1);				// 느린 함수를 통해 1의 갯수 체크
	printf("%d %d %.12fms\n", kTotal1, slow, cputime_n4);  // 실제 1의 개수 , 느린 함수를 통해 1의 갯수 체크한 값 , cputime 출력

	cputime_n5 = cputime_slow(b, n2);		    // 크기가 1000인 b라는 행렬에 대한 1의 갯수 셀 때 느린 함수에 대한 cputime 저장
	slow = countOnesButSlow(b, n2);				// 느린 함수를 통해 1의 갯수 체크
	printf("%d %d %.12fms\n", kTotal2, slow, cputime_n5);  // 실제 1의 개수 , 느린 함수를 통해 1의 갯수 체크한 값 , cputime 출력


	cputime_n6 = cputime_slow(c, n3);		    // 크기가 2000인 c라는 행렬에 대한 1의 갯수 셀 때 느린 함수에 대한 cputime 저장
	slow = countOnesButSlow(c, n3);				// 느린 함수를 통해 1의 갯수 체크
	printf("%d %d %.12fms\n", kTotal3, slow, cputime_n6);  // 실제 1의 개수 , 느린 함수를 통해 1의 갯수 체크한 값 , cputime 출력

	for (i = 0; i < n1; i++) {   //열에 대한 동적할당 해제
		free(a[i]);
	}
	for (i = 0; i < n2; i++) {   //열에 대한 동적할당 해제
		free(b[i]);
	}
	for (i = 0; i < n3; i++) {   //열에 대한 동적할당 해제
		free(c[i]);
	}

	free(a);					 //행에 대한 동적할당 해제
	free(b); 				     //행에 대한 동적할당 해제
	free(c);					 //행에 대한 동적할당 해제

	return 0;
}
