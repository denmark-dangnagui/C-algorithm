#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disabled:4996)
int n;

int Heap[100];

void downHeap(int i){
    int bigger, tmp;
    if(n < i*2 && n < i*2+1) // 말단 노드인지 즉, 자식노드가 있는지 확인
        return;
    bigger = i*2;
    if(i*2+1 <= n){
        if(Heap[bigger] < Heap[i*2+1])
            bigger = i*2+1;
    }
    if(Heap[i] >= Heap[bigger]) 
        return;
    tmp = Heap[i];
    Heap[i] = Heap[bigger];
    Heap[bigger] = tmp;
    downHeap(bigger);
}

void buildHeap(){ // n = 6
    for(int i = n/2 ; i > 0 ; i--){ // 3,2,1
        downHeap(i);
    }
}

void printHeap(){
    int i;
    for(i = 1 ; i < n + 1 ; i++){
        printf(" %d",Heap[i]);
    }
    printf("\n");
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