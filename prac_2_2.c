#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

int *queue;
int queuesize, front, rear,cnt;

void enqueue(int num){
    if(cnt == 0){
        queue[rear] = num;
        cnt++;
    }
    else{
        rear = (rear + 1) % queuesize;
        queue[rear] = num;
    }
}

void print(){
    for(int i = 0 ; i < queuesize ; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    int n, i, j, num, key, idx;
    cnt = 0;
    scanf("%d",&queuesize);
    queue = (int *)malloc(sizeof(int) * queuesize);
    for(i = 0 ; i < queuesize ; i++){
        queue[i] = 0;
    }
    for(i = 0 ; i < queuesize; i++){
        scanf("%d",&num);
        enqueue(num);
    }
    for(i = 1 ; i < queuesize ; i++){
        key = queue[i];
        for(j = i - 1; j >= 0; j--){
            if(queue[j] > key){                 // 이부분부터 정렬 다시 생각 
                queue[j + 1] = queue[j];
            }
            else{ 
                break;
            }
        }
        queue[j+1] = key;
        print();

    }
    free(queue);
}