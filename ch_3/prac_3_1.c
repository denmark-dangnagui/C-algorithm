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

void downHeap(int i) {
	int bigger, temp;
	if ((n < (i * 2)) && (n < (i * 2 + 1))) {
		return;
	}
	bigger = i * 2;
	if (n >= i * 2 + 1) { // 비교할 대상이 있는지 확인부터 하는 것.
		if (Heap[i * 2 + 1] > Heap[bigger]) {
			bigger = i * 2 + 1;
		}
	}
	if (Heap[i] >= Heap[bigger]) {
		return;
	}
	temp = Heap[i];
	Heap[i] = Heap[bigger];
	Heap[bigger] = temp;
	downHeap(bigger);
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
    downHeap(1);
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