#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int *queue;
int queuesize, front, rear,cnt;

void enqueue(int num){
    if(rear == queuesize){
        printf("full\n");
    }   
    else{
        if(cnt == 0){
            queue[rear] = num;
            cnt += 1;
        }
        else{
            rear = (rear + 1) % queuesize;
            queue[rear] = num;
        }
    } 
}

void print(){
    for(int i = 0 ; i < queuesize; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    int i,n,temp, num;
    front = 0;
    rear = 0;
    scanf("%d",&queuesize);
    queue = (int *)malloc(sizeof(int) * queuesize);
    for(i = 0 ; i < queuesize ; i++){
        queue[i] = 0;       //초기화
    }
    cnt = 0;
    for(i = 0 ; i < queuesize ; i++){
        scanf("%d",&num);
        enqueue(num);
    }
    for(i = queuesize - 1 ; i > 0 ; i--){ // 7654321
        for(int j = i - 1; j >= 0 ; j--){
            if(queue[i] < queue[j]){
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    print();
    free(queue);
}
// 8 31 48 73 3 65 20 29