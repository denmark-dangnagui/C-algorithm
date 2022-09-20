#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disabled:4996)
int n;
int Heap[100];

void upHeap(){  // upheap이란, 부모노드가 자식노드보다 클때까지 교환
    int i = n, data = Heap[n]; // data = 8

    while(i != 1 && Heap[i / 2] < data){
        Heap[i] = Heap[i / 2];
        i /= 2;
    }
    Heap[i] = data;
}

void downHeap(){
    int i = 1, j, data = Heap[1]; 
    while(i <= n / 2){
        j = i * 2;
        if(j + 1 <= n &&(Heap[j] <= Heap[j+1])){
            j++;
        }
        if(Heap[j] <= data){
            break;
        }
        Heap[i] = Heap[j];
        i = j;
    }
    Heap[i] = data;
}

void insertitem(int key){
    n += 1;
    Heap[n] = key;
    upHeap();
}

int removemax(){
    int key = Heap[1];
    Heap[1] = Heap[n];
    n -= 1;
    downHeap();
    return key;
}


void printHeap(){
    int i;
    for(i = 1 ; i < n + 1 ; i++){
        printf(" %d",Heap[i]);
    }
    printf("\n");
}

int main(){
    int key,root;
    char order = '0';
    n = 0;
    while(order != 'q'){
        scanf("%c",&order);
        getchar();
        if(order == 'i'){
            scanf("%d",&key);
            getchar();
            insertitem(key);
            printf("0\n");
        }
        else if (order == 'd'){
            root = removemax();
            printf("%d\n",root);
        }
        else if (order =='p'){
            printHeap();
        }
    }
}