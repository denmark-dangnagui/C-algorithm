#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int *queue;                     // 큐 선언
int queuesize, front, rear,cnt; // 필요한 변수 선언

void enqueue(int num){          //큐에 넣을 함수 선언
    if(rear == queuesize){      // rear가 큐사이즈와 같을시엔 예외처리
        printf("full\n");
    }   
    else{
        if(cnt == 0){       // 배열의 0번째부터 들어가게 하기 위해 cnt로 조절
            queue[rear] = num;
            cnt += 1;       // 다시 이 조건문에 들어가게 하지 않기 위해 cnt 값 1추가
        }
        else{
            rear = (rear + 1) % queuesize;  // 1부터 rear값을 넣어주면서 queue안에 들어가게 함.
            queue[rear] = num;
        }
    } 
}

void print(){
    for(int i = 0 ; i < queuesize; i++){  // queuesize의 크기를 가진 queue를 처음부터 끝까지 출력
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    int i,j,n,temp, num, idx = 0; // 필요한 변수 선언
    front = 0;         // queue를 사용할 때 필요한 front 와 rear를 선언
    rear = 0;
    scanf("%d",&queuesize);  // queue 사이즈 입력
    queue = (int *)malloc(sizeof(int) * queuesize);  // queue 동적할당
    for(i = 0 ; i < queuesize ; i++){               //queue 초기화
        queue[i] = 0;
    }
    cnt = 0; // queue의 0번째부터 들어가게 하기 위해 cnt 0으로 초기화
    for(i = 0 ; i < queuesize ; i++){ // queue에 숫자를 넣기위해 함수호출하여 반복문 돌림
        scanf("%d",&num);
        enqueue(num);
    }
    for(i = queuesize - 1 ; i > 0 ; i--){ // queue의 뒷부분부터 정렬하기
        temp = queue[i];
        cnt = 0;
        for(j = i - 1; j >= 0 ; j--){   //선택정렬을 하기위해서 temp를 활용해서 바꿔줌.
                if(temp < queue[j]){
                    temp = queue[j];
                    idx = j;
                    cnt++;
                }
        }
        if(cnt != 0){
            queue[idx] = queue[i];
            queue[i] = temp;
        }
        // printf("\n");
        print();
    }
    print();
    free(queue);
}
// 8 31 48 73 3 65 20 29