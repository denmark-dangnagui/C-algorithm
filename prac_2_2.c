#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int *queue; //큐선언
int queuesize, front, rear,cnt; //큐 사용에 필요한 변수 선언

void enqueue(int num){  // 큐에 삽입하기 위한 함수 선언
    if(cnt == 0){   // 0의 자리부터 삽입하기 위해 선언, 예외처리는 따로 필요하지 않아서 하지 않음
        queue[rear] = num; 
        cnt++;      // 1의 자리부터 다시 넣기 위해 cnt로 rear의 자리를 조절하기 위해 cnt 사용
    }
    else{           // 1부터 queuesize에 맞게 들어가게 하기 위한 처리
        rear = (rear + 1) % queuesize;
        queue[rear] = num;
    }
}

void print(){   //큐에 들어가있는 것들을 출력하기 위한 함수 선언
    for(int i = 0 ; i < queuesize ; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    int n, i, j, num, key, idx;  // 필요한 변수 선언
    cnt = 0;                    
    scanf("%d",&queuesize);     // queuesize 입력
    queue = (int *)malloc(sizeof(int) * queuesize); // queue 동적할당
    for(i = 0 ; i < queuesize ; i++){ // queue 초기화
        queue[i] = 0;
    }
    for(i = 0 ; i < queuesize; i++){  // queue에 들어갈 수를 입력받고 enqueue 함수를 호출하여 queue에 삽입
        scanf("%d",&num);
        enqueue(num);
    }
    for(i = 1 ; i < queuesize ; i++){ // 삽입정렬 하기위해 queue[1]부터 비교하기 위해 반복문 돌리기 시작
        key = queue[i];               // 키값을 설정해 키 값의 앞부분을 비교
        for(j = i - 1; j >= 0; j--){  // 키값의 바로 앞부분부터 queue[0]까지 비교 반복문 시작
            if(queue[j] > key){       // queue[j] 값이 키값보다 크면 
                queue[j + 1] = queue[j]; //queue[j+1]에 queue[j]값을 넣어준다.
            }
            else{                     // 같은 수들이 배열에 겹쳐지지 않게 queue[j] 값이 작거나 같으면 바뀌지 않게 break를 걸어준다.
                break;
            }
        }
        queue[j+1] = key;  // 반복문을 나오게 된다면, j값은 반복문에서 계속 작아졌고, 반복문이 끝났을 때 j값 기준으로 앞에 값자리가 key값이 들어갈 자리이므로 이렇게 공식 선언
    }
    print();    // 최종적으로 queue에 있는 값들을 출력
    free(queue); // 메모리 해제
}