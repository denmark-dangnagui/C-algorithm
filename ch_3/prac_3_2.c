#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disabled:4996)
int n; // 전역변수와 배열선언
int Heap[100];

void downHeap(int i){
    int bigger, tmp; // 큰수의 인덱스를 받을 변수와 , 교환을 위한 tmp변수 선언
    if(n < i*2 && n < i*2+1) // 말단 노드인지 즉, 자식노드가 있는지 확인
        return;
    bigger = i*2; // 우선 자식노드중 왼쪽자식을 크다고 설정.
    if(i*2+1 <= n){  // 하나 더 큰 인덱스를 가진 것이 오른쪽 자식인지 체크하는 조건문 
        if(Heap[bigger] < Heap[i*2+1]) // 만일 자식노드 중 왼쪽 노드보다 오른쪽 노드가 크다면
            bigger = i*2+1; // 변수에 저장되는 것을 바꿔줌
    }
    if(Heap[i] >= Heap[bigger])   // 만일 Heap[i]의 key 값이 Heap[bigger] 보다 크다면 바꾸는 의미 없음
        return; 
    tmp = Heap[i];      // 교환과정
    Heap[i] = Heap[bigger];
    Heap[bigger] = tmp;
    downHeap(bigger);  // 재귀로 올라갈 수 있을 때까지 올라감
}

void buildHeap(){ // 
    for(int i = n/2 ; i > 0 ; i--){ // 전역변수 마지막 내부노드부터 역방향으로 루트까지 가게 하기위해서 이렇게 범위를 줌
        downHeap(i); // 각 위치에 맞게 이동할 수 있도록 downHeap 호출
    }
}

void printHeap(){
    int i;  // 변수선언
    for(i = 1 ; i < n + 1 ; i++){  // 배열이 1부터 키값을 넣어놨기 때문에[부모와 자식을 비교하기 용이하기 위해] 1부터 n까지 키 값 출력
        printf(" %d",Heap[i]);
    }
    printf("\n");
}

int main(){
    int i; // 변수 선언
    scanf("%d",&n); // 배열 크기 입력
    for(i = 1 ; i < n + 1 ; i++){ // 배열에 키값들 입력
        scanf("%d",&Heap[i]);
    }
    buildHeap();  // 배열에 들어가있는 키값들을 정렬하기 위해서 함수 호출
    printHeap(); // 배열 출력
}