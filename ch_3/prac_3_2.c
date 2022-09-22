#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disabled:4996)
int n;
int Heap[100];
void downHeap(int i){
    int bigger, temp;
    if(n < i*2 && n < i*2+1){ // 말단 노드인지 즉, 자식노드가 있는지 확인
        return;
    }
    bigger = i*2;
    if(i*2+1 <= n){
        if(Heap[bigger] < Heap[i*2+1]){
            bigger = i*2+1;
        }
    }
    if(Heap[i] >= Heap[bigger]){
        return;
    }
    temp = Heap[i];
    Heap[i] = Heap[bigger];
    Heap[bigger] = temp;
    downHeap(bigger);
}

void printHeap(){
    int i;
    for(i = 1 ; i < n + 1 ; i++){
        printf(" %d",Heap[i]);
    }
    printf("\n");
}

void buildHeap(){ // n = 6
    for(int i = n/2 ; i > 0 ; i--){ // 3,2,1
        downHeap(i);
    }
}

int main(){
    int key,root,i,keys[101];
    char order = '0';
    scanf("%d",&n);
    for(i = 1 ; i < n + 1 ; i++){
        scanf("%d",&Heap[i]);
    }
    buildHeap();
    printHeap();
}