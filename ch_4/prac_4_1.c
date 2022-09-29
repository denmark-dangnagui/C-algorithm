#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disabled:4996)
int n;      // 기존 힙 크기 및 키의 갯수 n선언
int Heap[100];  // 힙 배열 선언
int size;    // 제자리 힙 정렬 후 출력할 때 n을 대신해서 정렬된 키들을 모두 출력하기 위한 변수 선언

void printArray(){ // Heap을 
    int i;          // 필요한 변수 선언
    for(i = 1; i <= size ;i++){ // 반복문을 돌리면서, 1부터 크기만큼 배열 출력
        printf(" %d",Heap[i]);
    }
    printf("\n");
}
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
void inPlaceHeapSort(){ // 제자리 힙 정렬
    int i, temp;    // 필요 변수 선언
    buildHeap();    // 기존 배열에 있는 것들을 최대힙으로 들어갈 수 있게 하는 함수
    for(i = n ; i >= 2 ; i--){ // 최대힙으로 힙이 정렬되어 있으므로, 제일 작은 수와 제일 큰수를 바꾸기 위해서 i = n 부터 시작하여 총 1이 되기 전까지 돌리기 위해 범위 설정
        temp = Heap[1];     // 힙의 최대키와 최소키를 교환
        Heap[1] = Heap[i];
        Heap[i] = temp;
        n--;                // n-- 를 하는 이유는, 오름차순으로 정렬된 것이므로, 현재 루트힙에 들어가있는 수는 현재 저장된 키값들 중 가장 작은 값, 더불어 교환된 가장 큰 값을 갈 수 있는 말단에 보내고 정렬하기 위해 그것을 제외하고 고려하기 위해 n을 줄임.
        downHeap(1);       // 다운힙을 호출하여, 현재 가장 작은 값이 들어가있는 루트힙의 값을 가야되는 자리에 넣어두기 위해 함수 호출
    }  // 계속해서 반복하여, n을 줄여줬기 때문에, 점차 큰 값들은 다운힙에 고려되는 키 값들은 줄어들기 때문에, 결국 루트힙에는 최소값이 들어가는 제자리 힙 정렬 완성
}

int main(){
    int i; // 변수 선언
    scanf("%d", &n); // 키값 개수 및 생성 될 힙의 개수 선언
    size = n; // inplaceHeapSort를 호출하면 줄어들 n의 개수를 대신하기 위해 size에 n 값 따로 저장
    for(i = 1 ; i <= n ; i++){ // Heap에 1부터 저장하기 위해서 i = 1 부터 시작 n까지 반복문 돌림
        scanf("%d",&Heap[i]); 
    }
    inPlaceHeapSort(); // 함수를 호출하여 최대힙을 만들고 오름차순을 만들기 위해서 제자리 힙 정렬 
    printArray(); // Heap 출력
}