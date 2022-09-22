#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disabled:4996)
int n;      // 힙의 크기 n선언
int Heap[100];  // 힙 배열 선언

void upHeap(int i){  
    int tmp;
    if(i == 1)
        return;
    if(Heap[i] <= Heap[i/2])
        return;
    tmp = Heap[i];
    Heap[i] = Heap[i/2];
    Heap[i/2] = tmp;
    upHeap(i/2);
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
    tmp = Heap[i];      // 교환
    Heap[i] = Heap[bigger];
    Heap[bigger] = tmp;
    downHeap(bigger);
}

void insertitem(int key){
    n += 1; // n값의 초기값을 0으로 설정하기도 하였고, 애초에 1부터 시작해야 부모로부터 자식을 확인하기 용이
    Heap[n] = key;  // n에 해당하는 즉, 가장 마지막 위치에 키값을 저장
    upHeap(n);  // 해당 값이 제 위치에 갈 수 있게 함수 호출
}

int removemax(){
    int key = Heap[1]; // 키값에 root값을 즉 , 배열의 첫번째 값을 저장
    Heap[1] = Heap[n]; // 그 값에 가장 말단 즉, n번째에 있는 값을 저장
    n -= 1;  // 가장 큰 값을 없애고 가장 아래에 있는 값을 올리기 때문에 n값이 하나 줄었음을 표시
    downHeap(1); // 1을 대입하여 함수 호출 , 1번에 말단에 있는 값이 들어가있기 때문에 제자리로 돌아 갈 수 있도록 함수 호출
    return key;  // key값 반환
}


void printHeap(){
    int i;//변수선언
    for(i = 1 ; i < n + 1 ; i++){ // 배열의 인덱스 값의 1부터 키값이 들어가있으므로 1부터 n까지 반복문 돌리며 배열에 들어가있는 키 값들 출력
        printf(" %d",Heap[i]);
    }
    printf("\n");
}

int main(){
    int key,root;       //필요한 변수 선언
    char order = '0';   
    n = 0;          // 전역변수 n을 기본값 0으로 설정
    while(order != 'q'){    // 반복문을 돌려서 q가 입력될 때까지 계속 반복
        scanf("%c",&order);    // 명령 입력
        getchar();
        if(order == 'i'){      // 명령이 'i'일 경우
            scanf("%d",&key);  // 추가적으로 수를 입력 받음
            getchar();
            insertitem(key);   // 함수 호출하여 키값을 넣어줌
            printf("0\n");     // 함수를 넣고 0을 출력
        }
        else if (order == 'd'){  // 명령이 'd'일 경우
            root = removemax();  // root에 삭제될 값을 함수를 호출하여 저장함
            printf("%d\n",root); // 값 출력
        }
        else if (order =='p'){  // 명령이 'p'일 경우
            printHeap();        // 들어가 있는 모든 힙을 출력
        }
    }
}